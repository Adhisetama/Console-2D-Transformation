#include <iostream>
#include <cmath>

class Point
{
public:
    double x;
    double y;

    void setPoint(double x, double y) {
        this->x = x;
        this->y = y;
    }

    void translate(double tx, double ty) {
        this->x += tx;
        this->y += ty;
    }

    void scale(double sx, double sy) {
        this->x *= sx;
        this->y *= sy;
    }

    void reflect_x() {
        this->y *= -1;
    }

    void reflect_y() {
        this->x *= -1;
    }

    void rotate(double t) {
        double rad = t / 180.0 * M_PI;
        double temp_x = this->x;
        double temp_y = this->y;
        this->x = cos(rad)*temp_x - sin(rad)*temp_y;
        this->y = sin(rad)*temp_x + cos(rad)*temp_y;
    }

    std::string print() {
        double x = this->x, y = this->y;
        return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
    }

};



int main() {

    // ambil array point dari user
    int n;
    std::cout << "mau brp titik mniezz??\n -> ";
    std::cin >> n;

    Point P[n];
    for (int i=1; i<=n; i++)
    {
        double x,y;
        std::cout << "titik ke-"+std::to_string(i) << '\n';
        std::cout << "    x: ";
        std::cin >> x;
        std::cout << "    y: ";
        std::cin >> y;
        P[i-1].setPoint(x, y);
        std::cout << "  " << P[i-1].print() << '\n';
    }

    bool flag = true;
    while(flag)
    {
        int T;
        std::cout << "\n  ___ ___    _____                  __                    _   _          \n |_  )   \\  |_   _| _ __ _ _ _  ___/ _|___ _ _ _ __  __ _| |_(_)___ _ _  \n  / /| |) |   | || '_/ _` | ' \\(_-<  _/ _ \\ '_| '  \\/ _` |  _| / _ \\ ' \\ \n /___|___/    |_||_| \\__,_|_||_/__/_| \\___/_| |_|_|_\\__,_|\\__|_\\___/_||_|\n";
        std::cout << "    1. translasi\n    2. rotasi\n    3. scale\n    4. refleksi\n  pilih transformasi: ";
        std::cin >> T;
        switch (T)
        {
        case 1:
        {
            double tx,ty;
            std::cout << "  TRANSLASI\n    tx: ";
            std::cin >> tx;
            std::cout << "    ty: ";
            std::cin >> ty;
            for (Point &p : P) {
                p.translate(tx, ty);
                std::cout << p.print() << ' ';
            }
        } break;
        
        case 2:
        {
            double t;
            std::cout << "  ROTASI\n    t(deg): ";
            std::cin >> t;
            for (Point &p : P) {
                p.rotate(t);
                std::cout << p.print() << ' ';
            }
        } break;

        case 3:
        {
            double sx,sy;
            std::cout << "  SCALE\n    sx: ";
            std::cin >> sx;
            std::cout << "    sy: ";
            std::cin >> sy;
            for (Point &p : P) {
                p.scale(sx, sy);
                std::cout << p.print() << ' ';
            }
        } break;

        case 4:
        {
            int reflection;
            std::cout << "  REFLEKSI\n    1. terhadap sumbu-x\n    2. terhadap sumbu-y\n  -> ";
            std::cin >> reflection;
            for (Point &p : P) {
                if (reflection == 1)
                    p.reflect_x();
                else if (reflection == 0)
                    p.reflect_y();
                std::cout << p.print() << ' ';
            }
        } break;

        }
        std::cout << "\n\nlakukan transformasi selanjutnya?\n    1. ya\n    0. tidak\n  -> ";
        std::cin >> flag;
    }

return 0;
}