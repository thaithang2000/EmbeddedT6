# EmbeddedT6

# STRUCT & UNION
**STRUCT**

Struct sắp xếp data theo biến có byte lớn nhất

struct có kích thước là kích thước tổng member và bộ nhớ đệm (padding) và có địa chỉ là địa chỉ của member đầu tiên nên tùy vào cách sắp xếp các biến trong struct, ta sẽ có kích thước khác nhau nên ta phải sắp xếp sao cho tối ưu.

Khi nào dùng Struct: Struct cùng một thời điểm ta có thể chọn cùng lúc nhiều member
VD :

struct {

	uint8_t var1;   // 1 byte  
	uint32_t var2;  // 4byte   
	uint64_t var3;  // 8 byte  
}

Lần quét 1: lưu 1byte var1 và lưu được thêm 4byte var2 cùng 3byte bộ nhớ đệm. Lần quét 2: lưu hết 8 byte var3 => tổng hết 16 byte

struct {

	uint8_t var1;   // 1 byte  
	uint64_t var3;  // 8byte   
	uint32_t var2;  // 4 byte  
}

Lần quét 1: lưu 1byte var1 và 7byte bộ nhớ đệm. Lần quét 2: lưu hết 8 byte var3. Lần quét 3: lưu 4byte var2 và 4byte bộ nhớ đệm  => tổng hết 24 byte

**UNION**

union có kích thước là kích thước member lớn nhất (member chứ ko phải kiểu dữ liệu). 

Địa chỉ của union giống với địa chỉ các member dùng chung địa chỉ nên ta có thể thay đổi giá trị của union bằng cách thay đổi giá trị member

Khi nào dùng Union: Union có rất nhiều member và tại 1 thời điểm mình chỉ sử dụng 1 member trong đó thôi thì ta sẽ dùng Union (ví dụ: Khi đi ra HN, ta sẽ có nhiều cách di chuyển, nhưng ta chỉ có thể chọn 1 cách).

Vd

![Capture](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/78040569-2bfd-42ca-973c-f5a8c3331e76)

=> kích thước union = kích thước var2[10] =10*4=40byte, kích thước union = kích thước member (không phải kích thước kiểu dữ liệu)
có nghĩa là bằng kích thước của biến(var1,var2,var[3]) lớn nhất chứ không phải kiểu dữ liệu (uint8_t,float,uint64_t) lớn nhất

Vd 

![1](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/fb0f8e47-5d93-4ab3-b826-6dfe50b1d1a5)


=> xuất ra giá trị var1 là 0 3 4 6 4 5 vì xài chung địa chỉ với nhau nên khi thay đổi giá trị var2 và var3 var 1 cũng thay đổi theo thường được dùng trong việc giao tiếp giữa cái vđk mcu
union dùng khi phải đưa ra lựa chọn dùng 1 trong các member tại cùng 1 thời điểm còn struct thì dùng khi đc chọn nhiều member cùng lúc


# MARCO & FUNCTION
**MARCO**

Marco xảy ra trong quá trình tiền xử lý, lệnh #define được dùng để tạo marco

Vd: #DEFINE MAX 10

 #define CREATE_FUNC(name_func, cmd)   \
 void name_func(){                     \
      printf("%s\n", (char*)cmd);      \	    
 }
 
 Marco không có dấu chấm phẩy ở kết thúc vì không phải là câu lệnh
  
**FUNCTION**

Hàm được khai báo với chức năng giải quyết một vấn đề nhiều lần. Hàm có thể có và không có tham số. Hàm có vùng nhớ riêng khi được tạo program counter có chức năng đếm giá trị vùng nhớ từ 0x00 -> hết ví dụ program counter đếm tới 0x08 thì gặp funtion thì trước khi vào function vùng nhớ tiếp theo 0x09 được lưu vào stack counter rồi program counter mới trỏ vào vùng nhớ của function để đếm xong thì nó lấy giá trị 0x09 trong stack counter ra tiếp tục đếm.

Program counter (bộ đếm): là 1 thanh ghi quản lý bộ nhớ của lệnh sẽ được thực thi tiếp theo. CPU đọc địa chỉ của lệnh sẽ được thực thi tiếp theo được lưu trữ trong bộ đếm chương trình và thực thi nó theo trình tự.

Stack pointer: lưu địa chỉ của item gần đây nhất được đặt trên ngăn xếp. (lưu địa chỉ ngẫu nhiên).

**Ưu nhược điểm**

Ưu điểm của function là không tốn thêm kích thước nếu gọi hàm đó nhiều lần vì đã có vùng nhớ riêng cho function nhưng tốc độ lại chậm hơn vì mỗi lần gọi nó lại phải trỏ lại vùng nhớ lưu function đó nó ngược với define về ưu nhược điểm. Define nó chỉ thay biến bằng giá trị nên trong quá trình complier mỗi khi gặp biến đc define nó chỉ thay bằng giá trị vd MAX thì được thay bằng 10 nên program counter sẽ tiếp tục đếm tiếp khi gặp biến define làm cho tốn thêm kích thước lưu trữ

# COMPILER
Compiler được hiểu như quá trình biên dịch các ngôn ngữ bậc cao thành các ngôn ngữ máy, cụ thể như ở ngôn ngữ C là quá trình biên dịch file main.c thành file main.exe qua bốn giai đoạn :


![11](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/ac78b520-dea8-4ed8-aa6e-ccf4d5608a2d)

Giai đoạn 1: là quá trình tiền xử lý (Preprocessor) từ source file (file main.c) tạo ra preprocessed source file (file main.i), quá trình này sẽ loại bỏ các lệnh include, define, comment và gộp các file thư viện được khai báo thành 1 file duy nhất. Ta có thể hiểu rằng nó sẽ thay các dòng #include <thư viện> thành các hàm trong thư viện đó, loại bỏ các comment và khai báo define.

Câu lệnh: gcc -E main.c -o main.i.

Giai đoạn 2: là quá trình compiler từ file main.i tạo ra file main.s (assembly code)

Câu lệnh : gcc main.i -S -o main.s

Giai đoạn 3: là quá trình assembler từ file main.s tạo ra file main.o(object file) và libaries(các file giao diện, âm thanh)

Câu lệnh : gcc -c main.s -o main.o.

Giao đoạn 4: là quá trình linker từ file main.o tạo ra file main.exe (đối với máy tính) và file main.h để nạp vào vi điều khiển (đối với vi điều khiển) và executable (gồm các file hình, video từ libaries) 
