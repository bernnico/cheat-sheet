#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>
#include <QCoreApplication>

QMutex mutex;
QWaitCondition condition;
bool dataReady = false;  // Eine zusätzliche Bedingung, um die Datenverfügbarkeit anzuzeigen

class Producer : public QThread {
public:
    void run() override {
        while (true) {
            {
                QMutexLocker locker(&mutex); // Sperrt das mutex
                qDebug() << "Producing data...";
                dataReady = true;  // Setzt die Bedingung, dass Daten bereit sind
                condition.wakeOne(); // Weckt einen wartenden Thread auf
                // mutex wird automatisch freigegeben, wenn locker zerstört wird
            }
            QThread::sleep(1);  // Wartet eine Sekunde, bevor der nächste Datenzyklus beginnt
        }
    }
};

class Consumer : public QThread {
public:
    void run() override {
        while (true) {
            QMutexLocker locker(&mutex); // Sperrt das mutex
            while (!dataReady) {  // Wartet, bis die Bedingung erfüllt ist
                qDebug() << "Waiting for data...";
                condition.wait(&mutex); // Wartet auf das Signal und gibt mutex frei
                // mutex wird automatisch gesperrt, wenn wait() zurückkehrt
            }
            qDebug() << "Data received!";
            dataReady = false;  // Setzt die Bedingung zurück
            // mutex wird automatisch freigegeben, wenn locker zerstört wird
        }
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);  // Notwendig für Qt-Threading

    Producer producer;
    Consumer consumer;
    
    consumer.start();  // Startet den Consumer-Thread
    producer.start();  // Startet den Producer-Thread
    
    producer.wait();  // Wartet, bis der Producer-Thread endet (niemals in diesem Fall)
    consumer.wait();  // Wartet, bis der Consumer-Thread endet (niemals in diesem Fall)
    
    return 0;
}
