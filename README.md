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

# POINTER
**NORMAL POINTER**

Trên ram có địa chỉ vùng nhớ đại diện cho các biến được khai báo. Trên Ram có 2 phần gồm địa chỉ và giá trị của địa chỉ. kích thước con trỏ phụ thuộc vào kiến trúc vi xử lý. Con trỏ dùng để lưu địa chỉ của biến được khai báo

Cách khai báo

int a = 10;   (giả sử địa chỉ a = 0x01)

int *ptr= 0x01; (khai báo biến con trỏ interger có giá trị là địa chỉ có kiểu interger)

&a = 0x01(lấy giá trị địa chỉ của biến a)

*0x01 (lấy giá trị của địa chỉ là giá trị biến = 10)

Printf(“Dia chi: %p”, ptr); = printf (“Dia chi: %p”, &a);

Printf(“Gia tri: %d”, *ptr); = printf (“Gia tri: %d”, a);

**VOID POINTER**

Con trỏ kiểu dữ liệu nào chỉ lưu được giá trị kiểu dữ liệu đó ngoài trừ con trỏ void, con trỏ void chỉ trả về đc địa chỉ chứ k trả về giá trị địa chỉ được muốn trả về giá trị ta phải ép kiểu bằng cách:

(*kiểu dữ liệu)tên biến

**NULL POINTER**

Khi khai báo 1 con trỏ mà ko khai báo địa chỉ cho nó thì nó sẽ trỏ tới 1 địa chỉ rác (địa chỉ đó có thể là trùng với địa chỉ 1 biến trong của chương trình) nên khi khai báo 1 con trỏ mà chưa dùng ta gán con trỏ null  vd int *ptr = NULL;

**FUNCTION POINTER**

Con trỏ hàm có chức năng trỏ đến vị trí của 1 hàm. Nó có thể trỏ đến những hàm cùng kiểu dữ liệu và cùng input parameter

Vd: void (*ptr)(char,int); nó có thể trỏ đến những hàm kiểu void có inputparamrter là kiểu char và int

**POINTER TO POINTER**

Là con trỏ dùng để lưu địa chỉ của một con trỏ khác

Vd:
int *ptr = 0x01 (nhưng nó cũng có 1 địa chỉ giả sử 0xc1)

int **ptp = &ptr = 0xc1

# PHÂN VÙNG NHỚ
![image](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/c13bf7a4-e8b3-4cf5-b496-90bd5cfffdb9)

**TEXT**

Quyền truy cập chỉ Read và nó chưa lệnh để thực thi nên tránh sửa đổi instruction.

Chứa khai báo hằng số trong chương trình (.rodata). 

Source code lưu trên Ram được lưu ở phân vùng text

Vd: khai báo biến hằng const float pi = 3.14; biến pi được lưu ở phân vùng text ta chỉ có thể xuất pi hay dùng pi để tính toán chứ không thể thay đổi được giá trị của pi bằng cách gán pi = 10.5; Khi này chương trình sẽ báo lỗi.

**DATA**

Quyền truy cập là read-write.

Chứa biến toàn cục (global) or biến static (gồm global static và local static)  với giá trị khởi tạo khác không.

Được giải phóng khi kết thúc chương trình. Đối với vđk là khi tắt hệ thống

Vd:

![Capture](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/f5ff25e8-8f35-4bc5-a838-c0108d0accfe)

Các biến x,y,z được lưu ở vùng nhớ Data

**BSS**

Quyền truy cập là read-write.

Chứa biến toàn cục (global) or biến static (gồm global static và local static) với giá trị khởi tạo bằng không or không khởi tạo. khi gán giá trị cho biến thì nó vẫn lưu ở phân vùng Bss chứ không chuyển phân vùng lưu Data

Được giải phóng khi kết thúc chương trình. Đối với vđk là khi tắt hệ thống. 

Vd:

![Capture](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/7e7d3717-cb88-432f-96fd-f3d6d60615d6)

Các biến x,y,z được lưu ở vùng nhớ BSS và khi gán giá trị cho các biến chúng vẫn lưu ở vùng BSS chứ không chuyển sang Data.

**STACK**

Quyền truy cập là read-write.

Được sử dụng cấp phát cho biến local, input parameter của hàm,…

Sẽ được giải phóng khi ra khỏi block code/hàm

![Capture](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/807d6158-299b-4016-abb2-7fe07638bc48)

Khi vào hàm clear, các input parameter a,b sẽ được cấp cho 1 địa chỉ chưa được dùng trên RAM. Sau đó, gán giá trị a = x = 10, b = y = 5. Rồi gán a=0,b=0 rồi thoát khỏi hàm và giải phóng địa chỉ của a và b. Từ đó, ta thấy được hàm clear không làm thay đổi giá trị của x,y mà chỉ làm thay đổi giá trị của a,b. 

![Capture](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/8a8ac088-e5ac-4a62-b61a-0617034b66ce)

Lưu ý: Khi nào ta chỉ muốn đọc thông tin giá trị truyền vào thì ta dùng khai báo input parameter là biến, còn ta muốn thay đổi giá trị biến ta truyền vào thì ta dùng khai báo input parameter là con trỏ.

**HEAP**

Quyền truy cập là read-write.

Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc,Realloc…

Sẽ được giải phóng khi gọi hàm free,…

# STATIC_EXTERN_VOLATILE
**STATIC**

Static gồm static toàn cục (global) và static cục bộ (local). Được lưu ở phân vùng data hoặc bss và tồn tại hết vòng đời của chương trình.

*Static toàn cục (global) là biến, hàm được tạo ra và chỉ có giá trị trong file khởi tạo ra chúng. Vì là biến, hàm global nên ta có thể dùng chúng bất cứ khi nào cần nhưng không thể dùng chúng ở file khác vì là biến, hàm static.

*Static cục bộ (local) chỉ khởi tạo 1 lần duy nhất và giá trị sẽ không bị mất khi thoát khỏi hàm mà giá trị của biến có thể tích lũy.

**EXTERN**

Extern dùng để gọi một biến hay một hàm từ file khác (không phải static) để sử dụng. Khi khai báo hàm hay biến dùng extern ta không được gán giá trị cho chúng. 

Câu lệnh: extern <kiểu dữ liệu> <tên biến hoặc hàm>;

Cách build chương trình: gcc main.c "tên file muốn build" -o main. Cách chạy chương trình: ./main

**VOLATILE**

Biến volatile là biến thông báo cho complier biết không được tối ưu biến này (thường dùng cho các biến lấy giá trị cảm biến, các biến data không biết khi nào thay đổi, nhiều task chạy song song dùng chung 1 biến). Do compiler có chế độ tối ưu chương trình để tăng tốc độ của chương trình nên sẽ bỏ qua các câu lệnh không làm thay đổi giá trị hay các lệnh lặp được gọi là optimizing. Nhưng trong các trường hợp nêu trên, giá trị thay đổi nhưng compiler không nhận ra và thực hiện việc tối ưu khiến cho kết quá sai.

Câu lệnh: volatile <kiểu dữ liệu> <tên biến>;







