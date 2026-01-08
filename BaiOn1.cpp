// ĐỀ BÀI TỔNG HỢP: QUẢN LÝ DỰ ÁN PHẦN MỀM ĐA PHƯƠNG TIỆN
// Yêu cầu: Xây dựng hệ thống lớp để quản lý các dự án phần mềm của sinh viên, kết hợp các yếu tố về thời gian, tọa độ đồ họa, thông tin nhân sự và lưu trữ.
//=================================================================================================================================================================
// a. Nhóm lớp nền tảng (Base Classes)
// Lớp MyDate: Mô tả ngày tháng năm. Gồm: các thuộc tính ngày, tháng, năm; Hàm thiết lập; Hàm hiển thị dạng dd-mm-yyyy; Toán tử > để so sánh hai đối tượng MyDate.
// Lớp MyTime: Mô tả thời gian. Gồm: các thuộc tính giờ, phút, giây; Hàm thiết lập; Hàm nhập dữ liệu; Hàm hiển thị dạng hh:mm:ss.
// Lớp Point: Mô tả tọa độ điểm trên màn hình thiết kế. Gồm: các thuộc tính x, y; Hàm thiết lập; Hàm hiển thị; Khai báo một hàm bạn (friend function) để tính khoảng cách giữa hai đối tượng Point.
//=================================================================================================================================================================
// b. Nhóm lớp kế thừa trung gian
// Lớp MyColor: Mô tả màu sắc của dự án. Gồm: thuộc tính màu (số nguyên); Hàm thiết lập; Hàm hiển thị mã màu.
// Lớp Storage: Mô tả kho lưu trữ vật lý của dự án. Gồm: thuộc tính tên_kho và số_lượng_tồn. Hàm nhap_kho(int q) và xuat_kho(int q) để cập nhật số lượng.
// Lớp Person: Mô tả thông tin người thực hiện. Gồm: thuộc tính họ_tên, địa_chỉ, số_điện_thoại. Hàm thiết lập và hiển thị thông tin.
//=================================================================================================================================================================
// c. Nhóm lớp kế thừa phức hợp (Multiple & Multilevel Inheritance)
// Lớp DigitalFile: Kế thừa từ cả MyDate và MyTime (Kế thừa bội). Bổ sung: filename (xâu ký tự), filesize (số thực). Hàm thiết lập, hàm nhập và hàm hiển thị thông tin tệp kèm thời gian khởi tạo.
// Lớp SoftwareProject: Kế thừa từ DigitalFile và MyColor. Bổ sung: điểm_đánh_giá (số thực), tác_giả (thuộc kiểu lớp Person - Composition).
// Sử dụng thêm một thuộc tính là Point để xác định vị trí logo dự án.
// Viết toán tử > để so sánh hai dự án dựa trên điểm_đánh_giá.
// Lớp CommercialProject: Kế thừa từ SoftwareProject và Storage (Cấu trúc kế thừa phức tạp). Bổ sung: giá_thành (số thực). Hàm thiết lập, hàm hủy bỏ và hàm hiển thị toàn bộ thông tin dự án bao gồm: thông tin tệp, thời gian, màu sắc, tác giả, tọa độ logo, giá thành và số lượng trong kho.
//=================================================================================================================================================================
// d. Chương trình chính (Main Program)
// Viết chương trình thực hiện các công việc sau:
// Khai báo một mảng gồm n con trỏ đối tượng kiểu CommercialProject (với n nhập từ bàn phím).
// Nhập dữ liệu cho n đối tượng dự án trên.
// Thực hiện gọi hàm nhap_kho cho dự án đầu tiên và hiển thị lại thông tin.
// Sắp xếp danh sách các dự án theo thứ tự tăng dần của ngày khởi tạo (sử dụng toán tử > của lớp MyDate). Nếu trùng ngày, sắp xếp giảm dần theo điểm đánh giá (sử dụng toán tử > của lớp SoftwareProject).
// Tìm và hiển thị thông tin dự án có giá thành cao nhất.
// Tính khoảng cách từ logo của dự án đầu tiên đến logo của dự án cuối cùng (sử dụng hàm bạn của lớp Point).

// đã sử dụng ai để kiểm tra lỗi và sửa lại
#include <iostream>
#include <math.h>
#include <string>
#include <ctime>
using namespace std;

// Lớp MyDate:
// Mô tả ngày tháng năm. Gồm: các thuộc tính ngày, tháng, năm; Hàm thiết lập;
// Hàm hiển thị dạng dd-mm-yyyy; Toán tử > để so sánh hai đối tượng MyDate.

class MyDate
{
private:
    int ngay;
    int thang;
    int nam;

public:
    MyDate()
    {
        ngay = 0;
        thang = 0;
        nam = 0;
    }
    MyDate(int ngay, int thang, int nam)
    {
        this->ngay = ngay;
        this->thang = thang;
        this->nam = nam;
    }
    MyDate(MyDate &d)
    {
        ngay = d.ngay;
        thang = d.thang;
        nam = d.nam;
    }
    MyDate getMyDate()
    {
        return *this;
    }
    void setMyDate(int ngay, int thang, int nam)
    {
        this->ngay = ngay;
        this->thang = thang;
        this->nam = nam;
    }
    friend ostream &operator<<(ostream &os, MyDate &d);
    friend istream &operator>>(istream &is, MyDate &d);

    bool operator>(MyDate &d);
};

// Lớp MyTime:
// Mô tả thời gian. Gồm: các thuộc tính giờ, phút, giây;
// Hàm thiết lập; Hàm nhập dữ liệu; Hàm hiển thị dạng hh:mm:ss.
class MyTime
{
private:
    int gio;
    int phut;
    int giay;

public:
    MyTime()
    {
        gio = 0;
        phut = 0;
        giay = 0;
    }
    MyTime(int gio, int phut, int giay)
    {
        this->gio = gio;
        this->phut = phut;
        this->giay = giay;
    }
    MyTime(MyTime &t)
    {
        this->gio = t.gio;
        this->phut = t.phut;
        this->giay = t.giay;
    }
    void setMyTime(int gio, int phut, int giay)
    {
        this->gio = gio;
        this->phut = phut;
        this->giay = giay;
    }
    friend ostream &operator<<(ostream &os, MyTime &t);
    friend istream &operator>>(istream &is, MyTime &t);
};

// Lớp Point: Mô tả tọa độ điểm trên màn hình thiết kế.
// Gồm: các thuộc tính x, y;
// Hàm thiết lập; Hàm hiển thị;
// Khai báo một hàm bạn (friend function) để tính khoảng cách giữa hai đối tượng Point.
class Point
{
private:
    int x;
    int y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    Point(Point &t)
    {
        this->x = t.x;
        this->y = t.y;
    }

    friend ostream &operator<<(ostream &os, Point &t)
    {
        os << "[" << t.x;
        os << ";" << t.y << "]";
        return os;
    }
    friend istream &operator>>(istream &is, Point &t)
    {
        cout << "> x: ";
        is >> t.x;
        cout << "> y: ";
        is >> t.y;
        return is;
    }
    friend float distance(Point &p1, Point &p2);
};

// Lớp MyColor: Mô tả màu sắc của dự án.
// Gồm: thuộc tính màu (số nguyên);
// Hàm thiết lập; Hàm hiển thị mã màu.
class MyColor
{
private:
    int color;

public:
    MyColor()
    {
        color = 0;
    }
    MyColor(int color)
    {
        this->color = color;
    }
    MyColor(MyColor &t)
    {
        this->color = t.color;
    }
    friend ostream &operator<<(ostream &os, MyColor &t)
    {
        os << "[" << t.color << "]";
        return os;
    }
    friend istream &operator>>(istream &is, MyColor &t)
    {
        cout << "> color: ";
        is >> t.color;
        return is;
    }
};

// Lớp Storage: Mô tả kho lưu trữ vật lý của dự án.
// Gồm: thuộc tính tên_kho và số_lượng_tồn.
// Hàm nhap_kho(int q) và xuat_kho(int q) để cập nhật số lượng.
class Storage
{
private:
    string tenKho;
    int soLuongTon;

public:
    Storage()
    {
        tenKho = "";
        soLuongTon = 0;
    }
    Storage(string tenKho, int soLuongTon)
    {
        this->soLuongTon = soLuongTon;
        this->tenKho = tenKho;
    }
    Storage(Storage &t)
    {
        this->soLuongTon = t.soLuongTon;
        this->tenKho = t.tenKho;
    }
    void nhapKho(int p)
    {
        soLuongTon += p;
    }
    void xuatKho(int p)
    {
        soLuongTon -= p;
    }

    friend ostream &operator<<(ostream &os, Storage &t)
    {
        os << "[" << t.tenKho << "]: " << t.soLuongTon;
        return os;
    }
    friend istream &operator>>(istream &is, Storage &t)
    {
        cout << "> Ten kho: ";
        is.ignore();
        getline(is, t.tenKho);
        cout << "> So luong ton hien gio la: ";
        cout << t.soLuongTon << endl
             << "> Nhap so luong vao kho: ";
        int q;
        is >> q;
        t.nhapKho(q);
        return is;
    }
};

// Lớp Person: Mô tả thông tin người thực hiện.
// Gồm: thuộc tính họ_tên, địa_chỉ, số_điện_thoại.
// Hàm thiết lập và hiển thị thông tin.
class Person
{
private:
    string hoTen;
    string diaChi;
    int soDienThoai;

public:
    Person()
    {
        hoTen = "";
        diaChi = "";
        soDienThoai = 0;
    }
    Person(string hoTen, string diaChi, int soDienThoai)
    {
        this->soDienThoai = soDienThoai;
        this->diaChi = diaChi;
        this->hoTen = hoTen;
    }
    Person(Person &t)
    {
        this->soDienThoai = t.soDienThoai;
        this->diaChi = t.diaChi;
        this->hoTen = t.hoTen;
    }
    friend ostream &operator<<(ostream &os, Person &t)
    {
        os << "--> Ten: " << t.hoTen << endl;
        os << "--> Dia chi: " << t.diaChi << endl;
        os << "--> So dien thoai: " << t.soDienThoai;
        return os;
    }
    friend istream &operator>>(istream &is, Person &t)
    {
        cout << "> Ten: ";
        is.ignore();
        getline(is, t.hoTen);
        cout << "> Dia chi: ";

        getline(is, t.diaChi);
        cout << "> So dien thoai: ";
        is >> t.soDienThoai;
        return is;
    }
};

// Lớp DigitalFile: Kế thừa từ cả MyDate và MyTime (Kế thừa bội).
// Bổ sung: filename (xâu ký tự), filesize (số thực).
// Hàm thiết lập, hàm nhập và hàm hiển thị thông tin tệp kèm thời gian khởi tạo.
class DigitalFile : public MyDate, public MyTime
{
private:
    string fileName;
    float fileSize;

public:
    DigitalFile() : MyDate(), MyTime()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        setMyDate(ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
        setMyTime(ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
        fileName = "";
        fileSize = 0;
    }
    DigitalFile(string fileName, int fileSize, MyDate d, MyTime t) : MyDate(d), MyTime(t)
    {
        this->fileSize = fileSize;
        this->fileName = fileName;
    }
    DigitalFile(DigitalFile &t) : MyDate(t), MyTime(t)
    {
        this->fileSize = t.fileSize;
        this->fileName = t.fileName;
    }
    friend ostream &operator<<(ostream &os, DigitalFile &t)
    {
        os << "> Ten file: " << t.fileName << endl;
        os << "- > Dung luong: " << t.fileSize << endl;
        os << "- > Thoi gian: " << endl;
        os << "-- > Gio: " << static_cast<MyTime &>(t) << endl;
        os << "-- > Ngay: " << static_cast<MyDate &>(t) << endl;
        return os;
    }
    friend istream &operator>>(istream &is, DigitalFile &t)
    {
        cout << "> Ten file: ";
        is.ignore();
        getline(is, t.fileName);
        cout << "- > Dung luong: ";
        is >> t.fileSize;
        return is;
    }
};

// Lớp SoftwareProject: Kế thừa từ DigitalFile và MyColor.
// Bổ sung: điểm_đánh_giá (số thực), tác_giả (thuộc kiểu lớp Person - Composition).
// Sử dụng thêm một thuộc tính là Point để xác định vị trí logo dự án.
// Viết toán tử > để so sánh hai dự án dựa trên điểm_đánh_giá.
class SoftwareProject : public DigitalFile, public MyColor
{
private:
    float diemDg;
    Person tacGia;
    Point logo;

public:
    SoftwareProject() : DigitalFile(), MyColor(), tacGia(), logo(), diemDg(0) {}
    SoftwareProject(float diemDg, Person tacGia, Point logo, DigitalFile d, MyColor m) : DigitalFile(d), MyColor(m), tacGia(tacGia), logo(logo), diemDg(diemDg) {}
    SoftwareProject(SoftwareProject &t) : DigitalFile(t), MyColor(t), tacGia(t.tacGia), logo(t.logo), diemDg(t.diemDg) {}
    bool operator>(SoftwareProject &d);
    float getDiemDG()
    {
        return diemDg;
    }
    Person getTacGia()
    {
        return tacGia;
    }
    Point getLogo()
    {
        return logo;
    }
    void setDiemDG(float d)
    {
        diemDg = d;
    }
    void setTacGia(Person d)
    {
        tacGia = d;
    }
    void setLogo(Point d)
    {
        logo = d;
    }
};

// Lớp CommercialProject: Kế thừa từ SoftwareProject và Storage (Cấu trúc kế thừa phức tạp).
// Bổ sung: giá_thành (số thực). Hàm thiết lập, hàm hủy bỏ và hàm hiển thị toàn bộ thông tin dự án bao gồm:
// thông tin tệp, thời gian, màu sắc, tác giả, tọa độ logo, giá thành và số lượng trong kho.
class CommercialProject : public SoftwareProject, public Storage
{
private:
    float giaThanh;

public:
    CommercialProject() : SoftwareProject(), Storage(), giaThanh(0) {}
    CommercialProject(float giaThanh, SoftwareProject sw, Storage s) : SoftwareProject(sw), Storage(s), giaThanh(giaThanh) {}
    CommercialProject(CommercialProject &c) : SoftwareProject(c), Storage(c), giaThanh(c.giaThanh) {}
    float getGiaThanh()
    {
        return giaThanh;
    }

    friend ostream &operator<<(ostream &os, CommercialProject &t)
    {
        Person tacGia = t.getTacGia();
        Point logo = t.getLogo();
        os << static_cast<DigitalFile &>(t);
        os << "-> Mau sac: " << static_cast<MyColor &>(t) << endl;
        os << "-> Tac gia: " << endl
           << tacGia;
        os << "-> Logo: " << logo << endl;
        os << "-> Gia thanh: " << (long long)t.giaThanh << endl;
        os << "-> Kho: " << static_cast<Storage &>(t) << endl;
        return os;
    }
    friend istream &operator>>(istream &is, CommercialProject &t)
    {
        is >> static_cast<DigitalFile &>(t);
        is >> static_cast<MyColor &>(t);
        cout << "* Tac gia: ";
        Person d;
        is >> d;
        t.setTacGia(d);
        cout << "* Logo: ";
        Point logo;
        is >> logo;
        t.setLogo(logo);
        cout << "* Gia thanh: ";
        is >> t.giaThanh;
        cout << "* Kho: ";
        is >> static_cast<Storage &>(t);
        ;
        return is;
    }
};

void quickSortProject(CommercialProject **ds, int l, int r);
bool checkDate(CommercialProject *a, CommercialProject *b);

int main()
{
    int n;
    cout << "Nhap so luong du an (n): ";
    cin >> n;

    CommercialProject **ds = new CommercialProject *[n];

    for (int i = 0; i < n; i++)
    {
        cout << endl
             << "======> NHAP DU LIEU CHO DU AN THU " << i + 1 << ":" << endl;
        ds[i] = new CommercialProject();
        cin >> *ds[i];
    }

    if (n > 0)
    {
        int q;
        cout << endl
             << "======> Nhap so luong can nhap vao kho cho du an dau tien: ";
        cin >> q;
        static_cast<Storage *>(ds[0])->nhapKho(q);
        cout << "Thong tin du an dau tien sau khi nhap kho:" << endl;
        cout << *ds[0] << endl;
    }
    quickSortProject(ds, 0, n - 1);
    cout << endl
         << "======> DANH SACH DU AN SAU KHI SAP XEP:" << endl;
    for (int i = 0; i < n; i++)
        cout << *ds[i] << endl;

    if (n > 0)
    {
        CommercialProject *maxGia = ds[0];
        for (int i = 1; i < n; i++)
        {
            if (ds[i]->getGiaThanh() > maxGia->getGiaThanh())
                maxGia = ds[i];
        }
        cout << endl
             << "======> DU AN CO GIA THANH CAO NHAT:" << endl;
        cout << *maxGia << endl;
    }

    if (n >= 2)
    {
        Point logo1 = ds[0]->getLogo();
        Point logo2 = ds[n - 1]->getLogo();
        float kc = distance(logo1, logo2);
        cout << endl
             << "======> Khoang cach tu Logo du an dau tien den Logo du an cuoi cung: " << kc << endl;
    }
    return 0;
}

// Mydate
ostream &operator<<(ostream &os, MyDate &d)
{
    if (d.ngay < 10)
        os << "0";
    os << d.ngay << "-";
    if (d.thang < 10)
        os << "0";
    os << d.thang << "-" << d.nam;
    return os;
}

istream &operator>>(istream &is, MyDate &d)
{
    bool boolCheck = true;
    while (boolCheck)
    {
        do
        {
            cout << "> Ngay: ";
            while (!(is >> d.ngay) || d.ngay < 1)
            {
                is.clear();
                is.ignore(1000, '\n');
                cout << " Sai! > Ngay: ";
            }
            if (d.ngay > 31)
                cout << "Sai! Qua so ngay ";
        } while (d.ngay > 31);

        do
        {
            cout << "> Thang: ";
            while (!(is >> d.thang) || d.thang < 1)
            {
                is.clear();
                is.ignore(1000, '\n');
                cout << " Sai! > Thang: ";
            }
            if (d.thang > 12)
                cout << "Sai! Qua so thang ";
        } while (d.thang > 12);

        cout << "> Nam: ";
        while (!(is >> d.nam) || d.nam < 1)
        {
            is.clear();
            is.ignore(1000, '\n');
            cout << " Sai! > Nam: ";
        }
        if (d.thang == 2)
        {
            if ((d.nam % 400 == 0) || (d.nam % 4 == 0 && d.nam % 100 != 0))
            {
                boolCheck = false;
            }
            else if (d.ngay <= 28)
            {
                boolCheck = false;
            }
            else
            {
                cout << " Sai! Kiem tra thang 2 ";
            }
        }
        else if (d.thang == 4 || d.thang == 6 || d.thang == 9 || d.thang == 11)
        {
            if (d.ngay <= 30)
            {
                boolCheck = false;
            }
            else
            {
                cout << " Sai! Qua 30 ngay ";
            }
        }
        else if (d.thang == 1 || d.thang == 3 || d.thang == 7 || d.thang == 8 || d.thang == 10 || d.thang == 12)
        {
            if (d.ngay <= 31)
            {
                boolCheck = false;
            }
            else
            {
                cout << " Sai! Qua 31 ngay ";
            }
        }
    }
    return is;
}

bool MyDate::operator>(MyDate &d)
{
    if (nam != d.nam)
        return nam > d.nam;
    if (thang != d.thang)
        return thang > d.thang;
    return ngay > d.ngay;
}

// MyTime
ostream &operator<<(ostream &os, MyTime &t)
{
    if (t.gio < 10)
        os << "0";
    os << t.gio << "h-";
    if (t.phut < 10)
        os << "0";
    os << t.phut << "p-";
    if (t.giay < 10)
        os << "0";
    os << t.giay;
    return os;
}
istream &operator>>(istream &is, MyTime &t)
{
    cout << "> Gio: ";
    while (!(is >> t.gio) || t.gio < 1)
    {
        is.clear();
        is.ignore(1000, '\n');
        cout << " Sai! > Gio: ";
    }

    do
    {
        cout << "> Phut: ";
        while (!(is >> t.phut) || t.phut < 1)
        {
            is.clear();
            is.ignore(1000, '\n');
            cout << " Sai! > phut: ";
        }
        if (t.phut > 60)
            cout << "Sai! Qua so phut ";
    } while (t.phut > 60);

    do
    {
        cout << "> Giay: ";
        while (!(is >> t.giay) || t.giay < 1)
        {
            is.clear();
            is.ignore(1000, '\n');
            cout << " Sai! > Giay: ";
        }
        if (t.giay > 60)
            cout << "Sai! Qua so Giay ";
    } while (t.giay > 60);
    return is;
}
// Point
float distance(Point &p1, Point &p2)
{
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}
// Lớp SoftwareProject
bool SoftwareProject::operator>(SoftwareProject &d)
{
    if (diemDg > d.diemDg)
    {
        return true;
    }
    return false;
}
// CommercialProject
void quickSortProject(CommercialProject **ds, int l, int r)
{
    int i = l;
    int j = r;
    CommercialProject *p = ds[(l + r) / 2];
    while (i <= j)
    {
        while (checkDate(ds[i], p))
            i++;
        while (checkDate(p, ds[j]))
            j--;
        if (i <= j)
        {
            CommercialProject *temp = ds[i];
            ds[i] = ds[j];
            ds[j] = temp;
            i++;
            j--;
        }
    }
    if (i < r)
    {
        quickSortProject(ds, i, r);
    }
    if (j > l)
    {
        quickSortProject(ds, l, j);
    }
}

bool checkDate(CommercialProject *a, CommercialProject *b)
{
    MyDate &da = static_cast<DigitalFile &>(*a);
    MyDate &db = static_cast<DigitalFile &>(*b);

    if (da > db)
        return false;
    if (db > da)
        return true;

    return a->getDiemDG() > b->getDiemDG();
}
