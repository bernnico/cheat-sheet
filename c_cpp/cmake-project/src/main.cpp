#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <exiv2/exiv2.hpp>
#include <filesystem>
#include <iostream>

constexpr int WORKING_IMG_COLS = 3680;
constexpr int WORKING_IMG_ROWS = 2456;

cv::Mat correctOrientation(const cv::Mat& src, int orientation) {
    cv::Mat dst;
    // Die Kamera wurde beim Aufnehmen des Bildes im/gegen den Uhrzeigersinn gedreht.
    // Dieser Wert wird in 'orientation' (sieheh exif.image.orientation) gespeichert.
    // Um das Bild correct anzuzeigen, muss es in die umgekehrte Richtung gedreht werden.
    switch (orientation) {
        case 1:
            // Normal
            dst = src.clone();
            break;
        case 2:
            // Spiegelung entlang der vertikalen Achse
            cv::flip(src, dst, 1);
            break;
        case 3:
            // 180 Grad Drehung
            cv::rotate(src, dst, cv::ROTATE_180);
            break;
        case 4:
            // 180 Grad Drehung
            cv::rotate(src, dst, cv::ROTATE_180);
            // Spiegelung entlang der horizontalen Achse
            cv::flip(src, dst, 0);
            break;
        case 5:
            // 90 Grad im Uhrzeigersinn und Spiegelung entlang der vertikalen Achse
            cv::rotate(src, dst, cv::ROTATE_90_COUNTERCLOCKWISE);
            // Spiegelung entlang der horizontalen Achse
            cv::flip(dst, dst, 1);
            break;
        case 6:
            // 90 Grad im Uhrzeigersinn
            cv::rotate(src, dst, cv::ROTATE_90_COUNTERCLOCKWISE);
            break;
        case 7:
             // 90 Grad gegen den Uhrzeigersinn
            cv::rotate(src, dst, cv::ROTATE_90_CLOCKWISE);
            // Spiegelung entlang der horizontalen Achse
            cv::flip(dst, dst, 1);
            break;
        case 8:
            // 90 Grad gegen den Uhrzeigersinn
            cv::rotate(src, dst, cv::ROTATE_90_CLOCKWISE);
            break;
        default:
            dst = src.clone();
            break;
    }
    return dst;
}

int getExifOrientation(const std::string& imagePath) {
    try {
        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(imagePath);
        if (!image.get()) {
            std::cerr << "Fehler: Konnte das Bild nicht öffnen!" << std::endl;
            return 1; // Default orientation
        }

        image->readMetadata();
        Exiv2::ExifData &exifData = image->exifData();
        if (exifData.empty()) {
            std::cerr << "Fehler: Keine Exif-Daten im Bild gefunden!" << std::endl;
            return 1; // Default orientation
        }

        Exiv2::ExifKey key("Exif.Image.Orientation");
        auto it = exifData.findKey(key);
        if (it != exifData.end() && it->count() > 0) {
            return it->toLong();
        } else {
            return 1; // Default orientation
        }
    } catch (Exiv2::AnyError& e) {
        std::cerr << "Fehler beim Lesen der Exif-Daten: " << e.what() << std::endl;
        return 1; // Default orientation
    }
}

static cv::Mat correctSize(cv::Mat &src) {
    cv::Mat dst;
    cv::Mat temp;

    // Schritt 1: Skalierung 3680x2456 auf 1840x1228
    if (src.cols != WORKING_IMG_COLS || src.rows != WORKING_IMG_ROWS) {
        return dst; // empty
    }

    // Verwende INTER_NEAREST um Verzerrungen zu vermeiden
    cv::resize(src, temp, cv::Size(WORKING_IMG_COLS/2, WORKING_IMG_ROWS/2), 0, 0, cv::INTER_NEAREST);

    // Schritt 2: Zuschneiden auf 1228x1228 ==> Mitte
    cv::Rect roi((temp.cols - temp.rows) / 2, 0, temp.rows, temp.rows);

    dst = temp(roi);

    return dst;
}

int main() {
    const char DSC_5149[] = "../../data/2023-09-15-01-58/DSC_5149.TIF"; // Pfad zum Bild
    std::string filePath = std::filesystem::current_path().string() + "/" + DSC_5149;

    if (!std::filesystem::exists(filePath)) {
        std::cout << "File don't found: " << filePath << std::endl;
        return -1;
    }

    // Exif-Orientierung ermitteln
    int orientation = getExifOrientation(DSC_5149);
    std::cout << "Exif Orientation: " << orientation << std::endl;

    // Bild laden
    cv::Mat src = cv::imread(DSC_5149, cv::IMREAD_GRAYSCALE);
    if (src.empty()) {
        std::cerr << "Fehler: Konnte das Bild nicht laden!" << std::endl;
        return -1;
    }

    // Bild entsprechend der Exif-Orientierung korrigieren
    cv::Mat imgCorrOrientation = correctOrientation(src, orientation);
    cv::Mat imgCorrected = correctSize(imgCorrOrientation);

    // Korrigierte Dimensionen ausgeben
    std::cout << "Korrigierte Höhe des Bildes: " << imgCorrected.rows << std::endl;
    std::cout << "Korrigierte Breite des Bildes: " << imgCorrected.cols << std::endl;

    // Optional: Anzeige des Bildes
    cv::Mat srcResized;
    cv::resize(src, srcResized, cv::Size(), 0.5, 0.5, cv::INTER_NEAREST);
    cv::imshow("Original Image", srcResized);
    cv::imshow("Corrected Image", imgCorrected);
    cv::waitKey(0);

    // Speichern des korrigierten Bildes
    cv::imwrite("corrected_image.jpg", imgCorrected);

    return 0;
}

/*
    typedef std::vector<std::pair<int, Eigen::Vector2d>> SetOfStars;
    typedef std::vector<size::size_t> SetOfIndices

    QImage drawShape(QImage &image, SetOfStars &setOfStars, SetOfIndices &setOfIndices) {
    // image ist ein Bild, die punkte sollen auf diesem Bild gezeichnet werden.

    // ein Element vom setOfStars enthaelt einen Punkt und sein ID > 0
    // SetOfStars ist eine Menge von Elementen

    // setOfIndices >= 3 enthaelt Indizes von Punkten die sich in setOfStars befinden 
    // und gezeichnet werden muessen.

    // das soll dann ungefaehr so aussehen, aber du kannst es machen wie du es willst.
    for (SetOfIndices &idx : setOfIndices) {
        size_t indexInSetOfStars = idx;

        // form: Ein Punkt soll als nicht gefuellte Kreis gezeichnet werden.
        // color: Orange wenn setOfIndices[0], sonst Blau
        // 
        // ein Punkt soll mit dem vorherigen Punkt mit einer Linie verbunden werden.
        // der erste Punkt soll mit dem letzten verbunden werden.
        drawPoint(image, setOfStars[indexInSetOfStars], form, color);
    }
    // alle andere Punkte sollen wie folgt gezeichnet werden
    for (SetOfStars &star, setOfStars) {
        // form: nicht gefuellte Quadrate
        // color: ist gruen
        if(ist_der_star_im_vorherigen_loop_gezeichnet_wurde == false)
            drawPoint(image, star, form, color);
    }

    }
*/
