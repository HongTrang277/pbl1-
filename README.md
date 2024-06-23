# PBL1- Đồ án lập trình tính toán
# Sinh viên thực hiện
  - Nguyễn Thị Hồng Trang : Nhóm trưởng
  - Phan Thanh Trường : Thành viên
    
# Link báo cáo
  https://tinyurl.com/BaoCaoPBL1
  
# Tình trạng hoàn thành
  Đã hoàn thành
  
# Ý tưởng
  Để giải quyết được đề tài, nhóm chúng em đã vận dụng các kiến thức về struct và mảng để tạo đa thức, các kiến thức nhập xuất file, sử dụng các thư viện tự tạo, và phương pháp giải hệ phương trình tuyến tính, ở đây là phép khử Gauss. 
  Các ý tưởng về những tính năng được cụ thể hóa qua việc khởi tạo một ma trận bằng mảng 2D trong các file *.txt, ma trận sẽ được đọc với kích thước (n,n+1) và được lưu vào chương trình. Từ những dữ liệu đã được đọc, nếu ma trận thỏa yêu cầu sẽ sử dụng phép khử Gauss để biến đổi về dạng ma trận bậc thang, sau đó giải hệ bằng quá trình ngược. Trong quá trình biến đổi, các thông báo đổi dòng nếu có sẽ được hiển thị. Từ ma trận ban đầu sẽ tính tổng các cột i, các tổng lần lượt là các hệ số tương ứng của một đa thức P(x). Các nghiệm của hệ phương trình đã giải lần lượt được thay vào P(x) và tính tổng Q(x). Sau khi đã có các dữ liệu cần thiết, sẽ lựa chọn để lưu các số liệu đã tính vào file
  Về phần tổ chức, sắp xếp chương trình, người dùng có thể nhập theo thứ tự các bước để đạt được những nhu cầu riêng. Tuy nhiên chương trình sẽ được cài đặt trong trường hợp nếu lựa chọn người dùng vẫn chưa đủ dữ liệu đầu vào cần thiết, sẽ tự động lấy ma trận mặc định và hoàn thành các bước trước đó. 

# Tổ chức chương trình 
Chương trình tổ chức một menu với 6 chức năng:
  -Nhập ma trận bằng tay: Người dùng sẽ nhập ma trận, và sau khi nhập xong sẽ hiện lên ma trận vừa nhập.
  -Đọc ma trận từ file: Chương trình sẽ kiểm tra tính hợp lệ của dữ liệu bao gồm kiểm tra có chứa ký tự chữ cái, có chứa nhiều hơn một dấu chấm trong một số, và kiểm tra sự đồng nhất về kích thước của các hàng trong ma trận. Nếu không thỏa mãn, nó trả về một mã lỗi tương ứngn ngược lại, nó trả về mã thành công.
  -Biến đổi ma trận và giải nghiệm: Sau khi biến đổi ma trận về ma trận tam giác trên, sẽ giải ma trận tam giác và xuất ra vecto nghiệm.
  -In ra đau thức P(x): Các hệ số của đa thức được tính bằng cách tổng các cột. Chương trình sẽ xử lý các trường hợp hệ số tự do, nếu hệ số của x là số 1, nếu số mũ là số 1 và dấu “+” không được hiển thị nếu đó là bậc cao nhất. 
  -Tính Q(x)= SUM(p(xi)) : Sử dụng vecto nghiệm để thế vào biểu thức và cộng các giá trị lại sẽ được Q(x).
Lưu dữ liệu vào file: Có thể lưu các bước giải hệ phương trình và vecto nghiệm. Lưu các kết quả của các đa thức vừa tính. Nếu lưu thành công, sẽ thông báo hiển thị “Đã lưu”. 



