#include <iostream>

class Base {
public:
    int publicMember = 1;
protected:
    int protectedMember = 2;
private:
    int privateMember = 3;
};

// FIRST /////////////////////////

class PublicDerived : public Base {
public:
    void showMembers() {
        std::cout << "publicMember: " << publicMember << std::endl;          // public in NextPublicDerived
        std::cout << "protectedMember: " << protectedMember << std::endl;    // protected in NextPublicDerived
        // std::cout << "privateMember: " << privateMember << std::endl;     // Zugriff NICHT erlaubt
    }
};

class ProtectedDerived : protected Base {
public:
    void showMembers() {
        std::cout << "publicMember: " << publicMember << std::endl;          // protected in NextProtectedDerived
        std::cout << "protectedMember: " << protectedMember << std::endl;    // protected in NextProtectedDerived
        // std::cout << "privateMember: " << privateMember << std::endl;     // Zugriff NICHT erlaubt
    }
};

class PrivateDerived : private Base {
public:
    void showMembers() {
        std::cout << "publicMember: " << publicMember << std::endl;          // private in NextPrivateDerived
        std::cout << "protectedMember: " << protectedMember << std::endl;    // private in NextPrivateDerived
        // std::cout << "privateMember: " << privateMember << std::endl;     // Zugriff NICHT erlaubt
    }
};

// NEXT //////////////////////////

class NextPublicDerived : public PublicDerived {
public:
    void showMembers() {
        std::cout << "publicMember: " << publicMember << std::endl;          // public in NextPublicDerived
        std::cout << "protectedMember: " << protectedMember << std::endl;    // protected in NextPublicDerived
    }
};

class NextProtectedDerived : protected ProtectedDerived {
public:
    void showMembers() {
        std::cout << "publicMember: " << publicMember << std::endl;          // protected in NextProtectedDerived
        std::cout << "protectedMember: " << protectedMember << std::endl;    // protected in NextProtectedDerived
    }
};

class NextPrivateDerived : private PrivateDerived {
public:
    void showMembers() {
        // std::cout << "publicMember: " << publicMember << std::endl;          // Zugriff NICHT erlaubt
        // std::cout << "protectedMember: " << protectedMember << std::endl;    // Zugriff NICHT erlaubt
    }
};

// MAIN  //////////////////////////

int main() {
    PublicDerived pd;
    pd.showMembers();
    std::cout << "Accessing from main: " << std::endl;
    std::cout << "pd.publicMember: " << pd.publicMember << std::endl;         // Zugriff erlaubt
    // std::cout << "pd.protectedMember: " << pd.protectedMember << std::endl; // Zugriff NICHT erlaubt
    // std::cout << "pd.privateMember: " << pd.privateMember << std::endl;     // Zugriff NICHT erlaubt

    ProtectedDerived protD;
    protD.showMembers();
    // std::cout << "protD.publicMember: " << protD.publicMember << std::endl; // Zugriff NICHT erlaubt
    // std::cout << "protD.protectedMember: " << protD.protectedMember << std::endl; // Zugriff NICHT erlaubt
    // std::cout << "protD.privateMember: " << protD.privateMember << std::endl;     // Zugriff NICHT erlaubt

    PrivateDerived privD;
    privD.showMembers();
    // std::cout << "privD.publicMember: " << privD.publicMember << std::endl; // Zugriff NICHT erlaubt
    // std::cout << "privD.protectedMember: " << privD.protectedMember << std::endl; // Zugriff NICHT erlaubt
    // std::cout << "privD.privateMember: " << privD.privateMember << std::endl;     // Zugriff NICHT erlaubt

    return 0;
}