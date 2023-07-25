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

# OOP (C++)
**CLASS**

Class hay lớp là một mô tả trừu tượng (abstract) của nhóm các đối tượng (object) có cùng bản chất, ngược lại mỗi một đối tượng là một thể hiện cụ thể (instance) cho những mô tả trừu tượng đó. Một class trong C++ sẽ có các đặc điểm sau:
 
 *Một class bao gồm các thành phần dữ liệu (thuộc tính hay property) và các phương thức (hàm thành phần hay method).
 
 *Class thực chất là một kiểu dữ liệu do người lập trình định nghĩa.
 
 *Trong C++, từ khóa class sẽ chỉ điểm bắt đầu của một class sẽ được cài đặt. 

![Capture](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/1d2db633-516e-4b60-8a15-1e9c655380d7)

**Access modifiers & properties declaration**

Access modifier là phạm vi truy cập của các thuộc tính và phương thức sẽ được khai báo bên dưới nó. Có 3 phạm vi truy cập trong C++ là public, private và protected.

*Các thuộc tính và phương thức khai báo public thì có thể được truy cập trực tiếp thông qua instance của class đó. Các thuộc tính nên khai báo là public nếu bạn không có ràng buộc điều kiện trước khi gán (người dùng có thể thoải mái gán giá trị) hoặc bạn không cần xử lý trước khi trả về giá trị thuộc tính.

*Các thuộc tính private thường được sử dụng khi bạn không mong muốn người khác có thể tùy ý gán giá trị hoặc là bạn muốn xử lý trước khi trả về 
giá trị.

*Đối với protected, các phương thức và thuộc tính chỉ có thể truy cập qua các class kế thừa nó hoặc chính nó.

![Capture](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/9f01ed54-caef-4054-8e0f-334dd96c980a)

**Method declaration**

Phương thức cũng giống như một hàm bình thường.Đối với phương thức thì có hai cách định nghĩa thi hành: định nghĩa thi hành trong lúc định nghĩa class và định nghĩa thi hành bên ngoài class.

Định nghĩa thi hành bên trong class:

![Capture](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/adf316fd-c56d-4b3d-b9fd-83919575d390)

Định nghĩa thi hành bên ngoài class:

![Capture](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/58501177-86be-4b42-81f3-f67b271a2786)

**Constructor**

Constructor hay hàm dựng là một hàm đặc biệt, nó sẽ được gọi ngay khi chúng ta 
khởi tạo một object.

![Capture](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/31171ca7-939a-4a91-a289-b0ff731e93ee)

**Destructor**

Có nhiệm vụ thu hồi lại bộ nhớ được cấp phát cho đối tượng thuộc lớp

**Static member**

Static member hay thành viên tĩnh trong class C++ cũng tương tự như với static variable (biến tĩnh) trong function. 

Đối với function, sau khi thực hiện xong khối lệnh và thoát thì biến tĩnh vẫn sẽ không mất đi. Đối với class, thành viên tĩnh sẽ là thuộc tính dùng chung cho tất cả các đối tượng của class đó, cho dù là không có đối tượng nào tồn tại. Tức là bạn có thể khai báo nhiều object, mỗi object các thuộc tính của nó đều khác nhau nhưng riêng static thì chỉ có một và static member tồn tại trong suốt chương trình cho dù có hay không có object nào của nó hay nói ngắn gọn là dùng chung một biến static

**Đặc tính của lập trình hướng đối tượng**

*Inheritance (Tính kế thừa ) trong lập trình hướng đối tượng có ý nghĩa, một class có thể kế thừa các thuộc tính của một class khác đã tồn tại trước đó.

Khi một class con được tạo ra bởi việc kế thừa thuộc tính của class cha thì chúng ta 
sẽ gọi class con đó là subclass trong C++, và class cha chính là superclass trong 
C++.
Có 3 kiểu kế thừa:

Kiểu public: Class cha là public, Class con là public. Class cha là protected, class con là protected. Class cha là private, không kế thừa.

Kiểu protected: Class cha là public, Class con là protected. Class cha là protected, class con là protected. Class cha là private, không kế thừa.

Kiểu private: Class cha là public, Class con là private. Class cha là protected, class con là private. Class cha là private, không kế thừa.

*Abstraction (Tính trừu tượng) trong lập trình hướng đối tượng là một khả năng 
mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông 
tin cần xử lý.

Điều đó có nghĩa, ta dùng một method, hay gán giá trị cho property (trong protected hay private) thông qua một method chính. Người dùng chỉ cần dùng 1 method duy nhất để có kết quả mong muốn.

Ví dụ đơn giản, chương trình tìm nghiệm phương trình bậc 2, ta chỉ cần nhập thông số của phương trình. Hệ thống sẽ xuất ra nghiệm, người dùng không cần biết quá trình xử lý ra nghiệm (tính delta, x1, x2) ra sao.

*Polymorphism (Tính đa hình) trong lập trình hướng đối tượng là một khả năng mà một phương thức trong class có thể đưa ra các kết quả hoàn toàn khác nhau, tùy thuộc vào dữ liệu được xử lý.

Ví dụ đơn giản, cùng là một class có thể có 2 method tên giống nhau nhưng input parameter khác nhau thì tùy vào input parameter nó sẽ dùng method nào

*Encapsulation (Tính đóng gói) trong lập trình hướng đối tượng có ý nghĩa không 
cho phép người sử dụng các đối tượng thay đổi trạng thái nội tại của một đối tượng, 
mà chỉ có phương thức nội tại của đối tượng có thể thay đổi chính nó.

Là không được truy cập trực tiếp từ property mà phải thông qua method.

Điều đó có nghĩa, dữ liệu và thông tin sẽ được đóng gói lại, giúp các tác động bên 
ngoài một đối tượng không thể làm thay đổi đối tượng đó, nên sẽ đảm bảo tính toàn 
vẹn của đối tượng, cũng như giúp dấu đi các dữ liệu thông tin cần được che giấu.

Ví dụ đơn giản, cùng là một class tìm nghiệm phương trình bậc 2, việc tính toán delta và căng delta ta không cho người dùng sửa đổi công thức đó

**Namespace**

Dùng khi file có nhiều biến hay hàm có tên giống nhau và tham số truyền vào nhưng có chức năng khác nhau. Để cho trình biên dịch hiểu được ta muốn dùng biến hay hàm nào ta dùng namespace.

Định nghĩa:

Namespace là từ khóa trong C++ được sử dụng để định nghĩa một phạm vi nhằm mục đích phân biệt các hàm, lớp, biến, ... cùng tên trong các thư viện khác nhau.

Cách khai báo: 

namespace Ten_namespace{
    khai bao ham, bien, class
}

![Capture](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/e30ed9f2-beea-4787-8a42-c3f46da7bf37)

Cách gọi hàm trong namespace:

![Capture](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/bbe2b5e1-51b1-4b8a-84e9-5e2aaa0e626d)

**Template**

Template (khuôn mẫu) là một từ khóa trong C++, và là một kiểu dữ liệu trừu tượng tổng quát hóa cho các kiểu dữ liệu int, float, double, bool...

Template trong C++ có 2 loại đó là function template & class template.

Template giúp người lập trình định nghĩa tổng quát cho hàm và lớp thay vì phải nạp chồng (overloading) cho từng hàm hay phương thức với những kiểu dữ liệu khác nhau.

VD: ![Capture](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/04bcbb76-5652-4875-a39a-00a885b45f6c)

**Hàm ảo(virtual function)**

Hàm ảo (virtual function) là một hàm thành viên trong lớp cơ sở mà lớp dẫn xuất khi kế thừa cần phải định nghĩa lại.

Hàm ảo được sử dụng trong trường hợp một method trong class cha được class con kế thừa và class con muốn thay đổi method đó (override).

Hàm ảo là một phần không thể thiếu để thể hiện tính đa hình trong kế thừa được hỗ trợ bởi nguồn ngữ C++.

Lưu ý: Con trỏ của lớp cơ sở có thể chứa địa chỉ của đối tượng thuộc lớp dẫn xuất, nhưng ngược lại thì không được.

Hàm ảo chỉ khác hàm thành phần thông thường khi được gọi từ một con trỏ. Sử dụng hàm ảo khi muốn con trỏ đang trỏ tới đối tượng của lớp nào thì hàm thành phần của lớp đó sẽ được gọi mà không xem xét đến kiểu của con trỏ.

**Vector**

Giống như là mảng (array), vector trong C++ là một đối tượng dùng để chứa các đối tượng khác, và các đối tượng được chứa này cũng được lưu trữ một cách liên tiếp 
trong vector.

Tuy nhiên, nếu như số lượng phần tử (size) của một mảng là cố định, thì ở vector, nó hoàn toàn có thể thay đổi trong suốt quá trình làm việc của chương trình

Các modifier
1. push_back(): Hàm đẩy một phần tử vào vị trí sau cùng của vector. Nếu kiểu của đối tượng được truyền dưới dạng tham số trong push_back() không giống với kiểu của vector thì sẽ bị ném ra.
  ten-vector.push_back(ten-cua-phan-tu);

2. assign(): Nó gán một giá trị mới cho các phần tử vector bằng cách thay thế các giá trị cũ.
ten-vector.assign(int size, int value);

3. pop_back(): Hàm pop_back () được sử dụng để xóa đi phần tử cuối cùng một vector.

4. insert(): Hàm này chèn các phần tử mới vào trước phần tử trước vị trí được trỏ bởi vòng lặp.Chúng ta cũng có thể chuyển một số đối số thứ ba, đếm số lần phần tử được chèn vào trước vị trí được trỏ.

5. erase(): Hàm được sử dụng để xóa các phần tử tùy theo vị trí vùng chứa

6. emplace(): Nó mở rộng vùng chứa bằng cách chèn phần tử mới vào

7. emplace_back(): Nó được sử dụng để chèn một phần tử mới vào vùng chứa vector, phần tử mới sẽ được thêm vào cuối vector

8. swap(): Hàm được sử dụng để hoán đổi nội dung của một vector này với một vector khác cùng kiểu. Kích thước có thể khác nhau.

9. clear(): Hàm được sử dụng để loại bỏ tất cả các phần tử của vùng chứa vector

**List**
List được hiểu như một mảng (array) nhân tạo do người dùng tạo ra. Đối với array hay vector thì các địa chỉ của các member là các địa chỉ liền kề nhau còn địa chỉ các member của list là ngẫu nhiên.

Cách khai báo list: list<kiểu dữ liệu> tên list;

Ta có thể dùng các modifier của vector cho list nhưng không thể dùng trực tiếp vì địa chỉ các member trong list là ngẫu nhiên nên phải dùng thông qua iterator

Cách khai báo iterator: list<kiểu dữ liệu>::iterator tên biến;

Vd:
![Capture](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/2dbd37f2-e6fc-47c8-b2bf-426dcc4da415)

![Capture](https://github.com/thaithang2000/EmbeddedT6/assets/136157839/b9647df0-d4dc-4abf-babe-2f3545275611)

**Lambda**
Là một hàm được tạo ra để sử dụng ngay lập tức nhầm tránh tình trạng lãng phí bộ nhớ
