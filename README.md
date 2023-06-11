# EmbeddedT6

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
