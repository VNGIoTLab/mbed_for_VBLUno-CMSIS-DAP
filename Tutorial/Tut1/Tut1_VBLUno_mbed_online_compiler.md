**mbed Tutorial 1: Lập trình ứng dụng cho mạch VBLUno với\
mbed Online Compiler**

**Nội dung trình bày:**

-   Giới thiệu hệ điều hành nhúng ARM mbed OS;

-   Giới thiệu bo mạch VBLUno của VNG IoTLab;

-   Giới thiệu công cụ nạp, debug chương trình BLE CMSIS-DAP Interface
    (DAPLink interface) của VNG IoTLab;

-   Hướng dẫn phát triển ứng dụng cho mạch VBLUno với trình biên dịch
    mbed Online Compiler.

**1. Giới thiệu hệ điều hành nhúng ARM mbed OS**

Khi xây dựng một hệ thống Internet of Things (IoT), việc lựa chọn
platform để thiết kế và xây dựng hệ thống là hết sức quan trọng. ARM Inc
là công ty sản xuất chip vi điều khiển ARM nổi tiếng, được ứng dụng rộng
rãi trong hệ thống nhúng và thiết bị di động. Với lợi thế của nhà thiết
kế chip, hãng cung cấp một nền tảng hoàn chỉnh để phát triển hệ thống
IoT với tên gọi **ARM mbed IoT Device Platform**.

![](media/image1.png){width="6.625in" height="2.1354166666666665in"}

*ARM mbed IoT Device Platform*

Thành phần quan trọng của ARM mbed IoT Device Platform chính là hệ điều
hành nhúng **mbed OS** cho các vi điều khiển Arm Cortex-M. mbed-OS được
cộng đồng đánh giá là hệ điều hành nhúng rất phù hợp để phát triển hệ
thống IoT với các tính năng cơ bản như: tính an ninh, nhiều giao diện
kết nối, có RTOS, nhiều thư viện cho các loại cảm biến và ngoại vi phổ
biến và đặc biệt nó là open-source. Chúng ta cùng xem xét một số tính
năng cơ bản của mbed OS.

-   ***Tính năng và lợi thế của mbed OS***

  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  **Hỗ trợ nhiều thiết bị**                   -   **mbed OS hỗ trợ nhiều loại chip ARM Cortex của các hãng sản xuất khác nhau (từ ARM Cortex M0 đến ARM Cortex M4).**
                                              
                                              -   **Hỗ trợ nạp chương trình cho chip bằng cách kéo thả (drag and drop programming) đơn giản, nhanh chóng**
                                              
                                              
  ------------------------------------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  **Thực thi phần mềm theo thời gian thực**   -   Với một nhân RTOS dựa trên CMSIS-RTOS RTX, mbed OS hỗ trợ multithread.
                                              
                                              

  **Mã nguồn mở**                             -   Được phát hành với giấy phép Apache 2.0, có thể sử dụng mbed OS với các dự án cá nhân hoặc thương mại
                                              
                                              

  **Dễ dàng sử dụng**                         -   Cấu trúc thư viện dạng mô đun
                                              
                                              -   mbed OS API: clean, portable, simple, whilst taking advantage of security and communications.
                                              
                                              -   Nhiều ví dụ minh họa
                                              
                                              

  **Cộng đồng hỗ trợ tốt**                    -   Trên 50 đối tác và hàng trăm ngàn nhà phát triển trên toàn thế giới
                                              
                                              -   Cộng đồng hỗ trợ tích cực trên trang mbed.org và github.com
                                              
                                              

  **End to End Security**                     Đảm bảo an ninh tại phần cứng, phần mềm, quá trình truyền thông :
                                              
                                              -   **Hardware Enforced Security** At the lowest level of mbed OS, we use a supervisory kernel called uVisor to create isolated security domains which restrict access to memory and peripherals.
                                              
                                              -   **Communications Security** We take SSL and TLS, the standard protocols for securing communications on the internet, and allow you to include them in your mbed project with a simple API.
                                              
                                              

  **Drivers và thư viện hỗ trợ**              -   Hỗ trợ đầy đủ các ngoại vi chuẩn của một MCU như: digital IO, analog IO, interrupts, port and bus IO, PWM, I2C, SPI và serial.
                                              
                                              -   Các thư viện C của mỗi toolchain được hỗ trợ cũng được tích hợp vào mbed OS
                                              
                                              
  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

-   ***Các giao diện kết nối được mbedOS hỗ trợ***

![](media/image2.png){width="5.979166666666667in"
height="2.9166666666666665in"}

-   ***Kiến trúc của mbed OS***

![](media/image3.png){width="6.375in" height="3.9479166666666665in"}

-   ***Các ứng dụng cơ bản của mbed OS***

![](media/image4.png){width="6.78125in" height="1.3958333333333333in"}

-   ***Các trang web hữu ích để tìm hiểu về mbed-OS***

<https://www.mbed.com/en/platform>

<https://www.mbed.com/en/platform/mbed-os/>

<https://docs.mbed.com/>

<https://developer.mbed.org/>

<https://github.com/ARMmbed/mbed-os>

**2. Giới thiệu bo mạch VBLUno của VNG IoTLab**

***\* Bo mạch VBLUno để làm gì?***

VBLUno (VNGIoTLab BLE Uno) là mô đun Bluetooth Low Energy (BLE) được
thiết kế mở rộng theo pinout tương thích chuẩn Arduino Uno, được tạo ra
với mục đích giúp cho các lập trình viên dễ dàng tiếp cận công nghệ BLE
và phát triển các sản phẩm ứng dụng trong Internet of Things (IoT).

Điểm nhấn của bo mạch VBLUno là mô đun BLE được các kỹ sư của VNGIoTLab
tự nghiên cứu và thiết kế. Đây cũng là mô đun đã và đang được sử dụng
trong nhiều sản phẩm thương mại của VNG như CSM Router, Gateway,…. Mô
đun BLE sử dụng chip nRF51822 của hãng Nordic Semiconductor, với nhân
ARM Cortex-M0 32bit hỗ trợ chuẩn giao tiếp Bluetooth Smart (BLE). Bên
cạnh các chuẩn truyền thông như 6LoWPAN, Zigbee, …, BLE được xem là
chuẩn truyền thông cực kỳ phù hợp dành cho IoT, với các ứng dụng truyền
thông khoảng cách gần và đặc biệt là độ tiêu thụ năng lượng cực kỳ thấp,
thân thiện với môi trường sống. Ví dụ như các hệ thống tòa nhà thông
minh, vườn thông minh, cửa hàng thông minh, quản lý trẻ em, quản lý nhân
viên, …

Với tinh thần chia sẻ và mong muốn cộng đồng IoT Việt Nam có thể tiếp
cận công nghệ BLE một cách dễ dàng nhất, VBLUno được công bố dưới dạng
mã nguồn mở, từ sơ đồ phần cứng, các mã nguồn chương trình ví dụ, mã
nguồn bootloader, mã nguồn công cụ upload, tài liệu hướng dẫn… Các bạn
có thể dễ dàng tham khảo cũng như tùy biến.

VBLUno hỗ trợ nhiều môi trường phát triển như mbed OS, Arduino IDE,…
*Bài viết này tập trung hướng dẫn phát triển ứng dụng với hệ điều hành
nhúng mbed OS.*

Ngoài ra các bạn có thể tham khảo hướng dẫn phát triển ứng dụng cho
VBLUno với công cụ Arduino IDE tại đường dẫn sau:

<https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822>

***\* Hình ảnh thực tế bo mạch VBLUno v1.0 và pinout dành cho ARM
mbed-OS***

![](media/image5.jpeg){width="6.510416666666667in" height="7.0625in"}

*Hình 1: Hình ảnh thực tế và pinout của bo mạch VBLUno*

***Chú ý:*** Sơ đồ chân của bo mạch VBLUno dành cho mbed OS khác với sơ
đồ chân của bo mạch VBLUno dành cho Arduino IDE.

***\* Thông số cơ bản của bo mạch VBLUno***

  ----------------------------------------------------------------------------------------------------------------------------------------
  **STT**   **Tính năng**                   **Mô tả**
  --------- ------------------------------- ----------------------------------------------------------------------------------------------
  0         Môi trường phát triển           -   mbed OS
                                            
                                            -   Arduino IDE
                                            
                                            -   …
                                            
                                            

  1         CPU                             Nordic nRF51822, nhân ARM Cortex-M0 32-bit

  2         Truyền thông không dây 2.4GHz   Hỗ trợ giao tiếp Bluetooth Low Energy hay còn gọi là Bluetooth Smart:
                                            
                                            +4dBm to -20dBm output power in 4dBm steps
                                            
                                            -30dBm output power in whisper mode
                                            
                                            -96dBm RX sensitivity at 250kbs
                                            
                                            -90dBm RX sensitivity at 1Mbps
                                            
                                            -85dBm RX sensitivity at 2Mbps
                                            
                                            2 Mbps, 1 Mbps and 250kbs supported data rates
                                            
                                            Excellent co-existence performance

  3         Xung nhịp hệ thống              16MHz

  4         Tiêu thụ năng lượng thấp        Ultra low power consumption
                                            
                                            6.3mA - TX at -4dBm (3V using on-chip DC-DC)
                                            
                                            8.0mA - TX at 0dBm (3V using on-chip DC-DC)
                                            
                                            11.8mA – TX at +4dBm (3V using on-chip DC-DC)
                                            
                                            9.7mA – RX (3V using on-chip DC-DC)
                                            
                                            13mA – RX at 1Mbps (No DC-DC)
                                            
                                            10.5mA – TX at 0dBm (No DC-DC)
                                            
                                            0.6µA – SYSTEM-OFF, no RAM retention
                                            
                                            1.2µA - SYSTEM-OFF, 8KB RAM retention
                                            
                                            2.6µA - SYSTEM-ON, All peripherals in idle mode

  5         Digital I/O                     21 kênh;
                                            
                                            Điện áp cực đại: +3.6V

  6         ADC                             6 kênh;
                                            
                                            Độ phân giải: 10bit
                                            
                                            Điện áp hoạt động: 0 ÷ +3.3V

  7         Timer                           3 bộ Timer 16bit với chế độ counter

  8         UART                            01 bộ

  9         SPI                             01 bộ

  10        I2C                             02 bộ

  11        PWM                             Tối đa 3 kênh tại cùng thời điểm;
                                            
                                            Chế độ 8bit, 16bit;
                                            
                                            Cấu hình PWM trên các kênh GPIO.

  12        Ngắt ngoài                      Cấu hình trên các kênh GPIO.

  13        Nạp/Gỡ lỗi chương trình         Sử dụng mô đun CMSIS-DAP (DAPLink) kết nối qua chuẩn SWD giúp nạp và gỡ lỗi một cách dễ dàng

  14        Nguồn cung cấp                  +5V ÷ +12V

  15        Pinout                          Thiết kế phù hợp pinout của Arduino Uno Rev3
  ----------------------------------------------------------------------------------------------------------------------------------------

-   **Chú ý:** VBLUno sử dụng chip Nordic nRF51822 cho phép cấu hình mềm
    chức năng trên các kênh vào ra số (Digital pin), điều đó có nghĩa
    bạn có thể cấu hình Serial, I2C, SPI, Interrupt, PWM trên bất kỳ
    kênh vào ra số nào.

> ***\* Bạn có thể mua mạch VBLUno ở đâu?***

Phần này không nhằm mục đích quảng cáo, chỉ mong muốn giúp các bạn có
thể tiết kiệm thời gian tìm kiếm thông tin. Để mua bo mạch VBLUno và mô
đun CMSIS-DAP của VNGIoTLab phục vụ học tập và nghiên cứu, các bạn có
thể truy cập hai đường dẫn sau:

> <http://www.iotviet.com.vn>
>
> <https://www.facebook.com/bleviet>

**3. Giới thiệu công cụ nạp, debug chương trình BLE CMSIS-DAP Interface
(DAPLink interface) của VNG IoTLab**

Với các bạn đã tìm hiều về điện tử, chúng ta khá quen thuộc với khái
niệm “mạch nạp”. Hiểu đơn giản là sau khi lập trình ứng dụng cho vi điều
khiển, bạn biên dịch ra một ***“file thực thi”*** mà phần cứng có thể
hiểu và thực hiện theo các lệnh bạn cài đặt, bạn cần một công cụ hỗ trợ
để nạp file thực thi xuống vi điều khiển.

Để hỗ trợ nạp chương trình cho bo mạch VBLUno, VNGIoTLab đã thiết kế mô
đun BLE CMSIS-DAP (tương thích DAPLink) giúp developer dễ dàng nạp
chương trình bằng cách kéo thả (Drap-and-Drop programming).

Ngoài tính năng nạp chương trình, mô đun CMSIS-DAP của VNGIoTLab còn hỗ
trợ developer gỡ lỗi chương trình thông qua phần mềm pyOCD GDB-Debugger
hoặc OpenOCD GDB-Debugger. Nói chung, đây là công cụ cần thiết và hiệu
quả giúp developer phát triển ứng dụng cho bo mạch VBLUno và nhiều bo
mạch khác.

Hình dưới mô tả cách kết nối mô đun CMSIS-DAP với mạch VBLUno:

![](media/image6.jpeg){width="6.416666666666667in"
height="2.7291666666666665in"}

**4. Hướng dẫn phát triển ứng dụng cho mạch VBLUno với trình biên dịch
mbed Online Compiler.**

Đúng như tên gọi của nó, mbed Online Compiler là một trình biên dịch
dành cho mbed OS chạy online, chỉ với một máy tính có kết nối internet,
bạn có thể dễ dàng lập trình và biên dịch ra file thực thi cho VBLUno.
Phần sau đây trình bày các bước thực hiện một cách chi tiết thông qua
hình ảnh.

**Bước 1: Đăng ký tài khoản trên developer.mbed.org**

*(Nếu đã đăng ký, bạn có thể bỏ qua bước này)*

Truy cập vào địa chỉ <https://developer.mbed.org> , đăng ký một tài
khoản dành cho các developer với mbed OS. Nó là hoàn toàn miễn phí nên
các bạn có thể tự tin đăng ký nhé.

**Bước 2: Đăng nhập giao diện trình biên dịch **

Nhấp vào nút **“Compiler”** hoặc truy cập vào đường dẫn
https://developer.mbed.org/compiler/

![](media/image7.png){width="6.5625in" height="2.1666666666666665in"}

**Bước 3: Chọn Device Platform để lập trình ứng dụng**

![](media/image8.png){width="5.322916666666667in"
height="2.7083333333333335in"}

Cửa sổ Select a Platform hiện ra, nhấn vào “Add platform”

![](media/image9.png){width="5.84375in" height="3.8229166666666665in"}

Bạn chọn board **Nordic nRF51822**. Đây là board có cấu hình phần cứng
khá tương đồng với VBLUno board

![](media/image10.png){width="6.520833333333333in"
height="3.0729166666666665in"}

Tiếp theo bạn chọn **“Add to your mbed compiler”**

![](media/image11.png){width="6.416666666666667in" height="2.40625in"}

Nếu thành công bạn sẽ nhận được công thông báo như hình dưới

![](media/image12.png){width="6.333333333333333in"
height="2.4166666666666665in"}

Nhấp vào nút Compiler để quay về trình biên dịch, lúc này góc phải của
trình duyệt sẽ hiển thị board Noridc nRF51822

![](media/image13.png){width="6.1875in" height="3.3645833333333335in"}

**Bước 4: Thực hiện một ví dụ đơn giản – Hello World Example**

Sau đây chúng ta thực hiện một ví dụ đơn giản, ví dụ “mbed\_blinky”.

-   ****4.1 Thêm một ví dụ sẵn có vào tài khoản của bạn****

> + Chọn **“import a program”, **
>
> + Tìm kiếm theo từ khóa “mbed\_blinky”
>
> + Chọn ví dụ mbed\_blinky trong danh sách tìm được, nhấn chọn
> **“Import”** để thêm ví dụ này vào tài khoản của bạn.

![](media/image14.png){width="6.697916666666667in"
height="3.1041666666666665in"}

-   ****4.2 Sửa mã nguồn chương trình “main.cpp”:****

Copy đoạn mã nguồn sau vào file main.cpp

![](media/image15.png){width="5.875in" height="4.208333333333333in"}

> Chọn Save để lưu lại

-   ****4.3 Chọn Compile để biên dịch chương trình****

Kết quả biên dịch thành công, tạo ra 1 file thực thi (\*.hex) và tự động
lưu về máy tính của bạn

![](media/image16.png){width="5.625in" height="2.15625in"}

-   ****4.4 Nạp file thực thi vào bo mạch VBLUno****

Sau khi kết nối bo mạch VBLUno và mô đun CMSIS-DAP đến máy tính, một ổ
đĩa sẽ được thêm vào máy tính của bạn. Ổ đĩa này có tên là “MBED” hoặc
“DAPLINK”. Để nạp file thực thi đã được biên dịch ở bước trước vào bo
mạch VBLUno, bạn chỉ cần copy file này vào ổ đĩa trên và chờ quá trình
sao chép hoàn tất.

![](media/image17.png){width="6.114583333333333in"
height="4.291666666666667in"}

-   ****4.5 Chạy chương trình****

Sau khi nạp file thực thi, chương trình sẽ tự động chạy. Nếu mọi việc
thành công, bạn sẽ thấy LED trên mạch VBLUno nhấp nháy sáng.

Sử dụng một phần mềm có chức năng Serial Terminal như Hercules hoặc
PuTTY, tạo một kết nối đến cổng COM ảo với tốc độ baud 9600, bạn sẽ quan
sát được thông điệp mà VBLUno gửi lên máy tính như hình dưới.

![](media/image18.png){width="6.479166666666667in" height="3.34375in"}

Bài viết này đã giới thiệu các nội dung cơ bản về bo mạch VBLUno, mô đun
CMSIS-DAP của VNGIoTLab. Bên cạnh đó cũng giới thiệu hệ điều hành nhúng
mbed OS, một hệ điều hành rất mạnh, phù hợp cho các thiết bị IoT. Phần
cuối cùng trình bày chi tiết các bước lập trình ứng dụng cho VBLUno bằng
trình biên dịch mbed Online. Với một máy tính kết nối internet, bạn có
thể dễ dàng xây dựng các chương trình ứng dụng cho VBLUno.

*Trong bài viết sau, mình sẽ hướng dẫn phát triển ứng dụng cho VBLUno
với môi trường offline: Eclipse + GCC ARM Embedded+ Nạp và Debug bằng
pyOCD hoặc OpenOCD.*

Cảm ơn bạn đã đọc tài liệu này. Mong nhận được ý kiến đóng góp của bạn.
Bạn có thể gửi phản hồi tại các địa chỉ sau:

<https://www.facebook.com/bleviet>

<https://github.com/VNGIoTLab/mbed_for_VBLUno-CMSIS-DAP>

---The END---
