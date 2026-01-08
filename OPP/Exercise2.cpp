/*
=====================================================================
ĐỀ BÀI TỔNG HỢP (NÂNG CAO)
HỆ THỐNG QUẢN LÝ ĐỐI TƯỢNG TOÁN HỌC VÀ LƯU TRỮ

Xây dựng một hệ thống lớp để quản lý các đối tượng toán học gồm:
Số phức, Vector động, Phân số, Ngày tháng và Thời gian.
Hệ thống phải áp dụng đầy đủ các đặc trưng của lập trình hướng đối tượng:
đóng gói, kế thừa, đa hình và trừu tượng.
=====================================================================

Câu 1.
Thiết kế lớp trừu tượng Entity thỏa mãn các yêu cầu sau:
- Khai báo các hàm ảo thuần túy input() và display().
- Bổ sung ít nhất một hàm ảo khác dùng cho so sánh hoặc tính toán.
- Cài đặt hàm hủy ảo để đảm bảo giải phóng bộ nhớ chính xác
  khi thao tác thông qua con trỏ lớp cơ sở.

-------------------------------------------------------------
Câu 2.
Xây dựng lớp MyComplex kế thừa từ Entity, với các yêu cầu:
- Lưu trữ phần thực và phần ảo của số phức.
- Nạp chồng các toán tử +, - (hàm bạn) và == (hàm thành viên).
- Ghi đè đầy đủ các hàm ảo của lớp Entity.
- Cho phép so sánh hai số phức dựa trên mô-đun.

-------------------------------------------------------------
Câu 3.
Xây dựng lớp MyVector kế thừa từ Entity, sử dụng cấp phát động:
- Cài đặt đầy đủ Rule of Three (Destructor, Copy Constructor,
  Copy Assignment Operator).
- Nạp chồng toán tử + và * (nhân với số thực).
- Tự động phát hiện và xử lý lỗi khi cộng hai vector khác kích thước.
- Ghi đè các hàm ảo input(), display() và hàm so sánh.

-------------------------------------------------------------
Câu 4.
Xây dựng lớp MyFraction kế thừa từ Entity, với các yêu cầu:
- Tự động chuẩn hóa phân số (mẫu luôn dương).
- Rút gọn phân số sau mỗi phép toán.
- Nạp chồng các toán tử >, >=, +, -, *, /.
- Cài đặt cơ chế so sánh thông qua hàm ảo của lớp cơ sở.

-------------------------------------------------------------
Câu 5.
Xây dựng các lớp MyDate và MyTime, trong đó:
- Cho phép so sánh chính xác thời điểm thông qua ngày và giờ.
- Xử lý các trường hợp biên (năm nhuận, số ngày trong tháng).
- Nạp chồng toán tử so sánh và ghi đè hàm ảo của Entity.

-------------------------------------------------------------
Câu 6.
Viết chương trình chính đáp ứng các yêu cầu sau:
- Sử dụng mảng hoặc vector con trỏ Entity* để quản lý đa hình.
- Cho phép nhập danh sách đối tượng với số lượng bất kỳ.
- Hiển thị danh sách bằng một lời gọi hàm duy nhất (đa hình).
- Tính tổng các đối tượng cùng kiểu mà không cần ép kiểu tường minh.
- Sắp xếp toàn bộ danh sách đối tượng dựa trên hàm so sánh ảo.
- Tìm kiếm một đối tượng bất kỳ trong danh sách.
- Đảm bảo giải phóng toàn bộ bộ nhớ động trước khi kết thúc chương trình.
=====================================================================
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;


// Câu 1.
// Thiết kế lớp trừu tượng Entity thỏa mãn các yêu cầu sau:
// - Khai báo các hàm ảo thuần túy input() và display().
// - Bổ sung ít nhất một hàm ảo khác dùng cho so sánh hoặc tính toán.
// - Cài đặt hàm hủy ảo để đảm bảo giải phóng bộ nhớ chính xác
//   khi thao tác thông qua con trỏ lớp cơ sở.


int main(){
    
}