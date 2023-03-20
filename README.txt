dokumentasi untuk class Point:

cara menggunakan:

1.  constructor menggunakan constructor default tanpa parameter.
    Namun, untuk dapat menggunakan instance dari Point harus menjalankan
    method Point.setPoint(x, y) terlebih dahulu.
    contoh code:
    Point p = new Point();
    p.setPoint(1, 2); // set titik p sebagai (1, 2)

2.  method Point.print() mereturn string berupa titik saat ini. Misalkan
    p memiliki nilai property x: 1 dan y: 2, maka Point.print() mereturn "(1, 2)"
    contoh code:
    std::cout << p.print() << std::endl;

3.  Transformasi
    Point.translate(tx, ty) mentranslasikan titik p dengan faktor tx dan ty
    Point.rotate(t)         merotasikan titik p dengan t derajat
    Point.scale(sx, sy)     menscale titik p dengan faktor sx dan sy
    Point.reflect_x()       pencerminan sumbu x
    Point.reflect_y()       pencerminan sumbu y
    ingat kembali bahwa operasi transformasi tidak mereturn apa apa dan hanya
    merubah property Point.x dan Point.y, untuk memprint value saat ini gunakan
    Point.print(), atau ambil value property x dan y.