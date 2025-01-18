#include <iostream>
#include <fstream>
#include <string>

class FileHandler {
public:
    void display(const std::string& path) {
        std::ifstream file(path);
        if (file.is_open()) {
            char c;
            while (file.get(c)) {
                std::cout << c;
            }
            std::cout << std::endl;
            file.close();
        } else {
            std::cout << std::endl;
        }
    }
};

class AsciiFileHandler : public FileHandler {
public:
    void display(const std::string& path) {
        std::ifstream file(path);
        if (file.is_open()) {
            char c;
            while (file.get(c)) {
                std::cout << (int)c << " ";
            }
            std::cout << std::endl;
            file.close();
        } else {
            std::cout << std::endl;
        }
    }
};

class BinaryFileHandler : public FileHandler {
public:
    void display(const std::string& path) {
        std::ifstream file(path);
        if (file.is_open()) {
            char c;
            while (file.get(c)) {
                for (int i = 7; i >= 0; i--) {
                    std::cout << ((c >> i) & 1);
                }
                std::cout << " ";
            }
            std::cout << std::endl;
            file.close();
        } else {
            std::cout << std::endl;
        }
    }
};

int main() {
    FileHandler basic;
    AsciiFileHandler ascii;
    BinaryFileHandler binary;

    std::string file = "example.txt";

    basic.display(file);
    ascii.display(file);
    binary.display(file);

    return 0;
}
