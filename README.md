# GameWorld-Project

**Đinh Văn Thạch**: 21020789.

**Lớp**: K66CD-CN1-UET.

**Môn học**: Lập trình nâng cao(INT2215_1).

**Email**: 21020789@vnu.edu.vn

#### **GIỚI THIỆU CHUNG**

GameWorld được phát triển dựa trên tựa game đua xe cổ điển né chướng ngại vật và các xe chạy ngược chiều với nó.

**Luật chơi:**

- **Người chơi điều khiển chiếc xe né các chướng ngại vật trên đường và các xe cộ chạy trên đường, tránh những va chạm trên đường.**
  - Nhấn UP để di chuyển lên trên.
  - Nhấn DOWN để di chuyển xuống.
  - Nhấn LEFT để di chuyển sang trái.
  - Nhấn RIGHT để di chuyển sang phải.
- **Điểm của người chơi chính bằng số giây từ lúc bắt đầu chơi đến lúc xảy ra va chạm.**
- **Khi càng lên cao số vàng bạn nhận được sẽ nhiều hơn,  đồng nghĩa với  đó là sẽ có nhiều thử thách hơn cho bạn đó nhá.**
- **Khi chơi người chơi có thể ăn các vật phẩm ở trên đường đi để cướng hóa sức mạnh cho chiếc xe.**

#### **CÁCH CÀI ĐẶT**

[Tải xuống tại đây:](https://drive.google.com/file/d/1ydovbY9XF1h_YOjeAGJi6rjWbDGCcEoi/view?usp=sharing)


Bước 1:Sau khi truy cập vào link click vào góc bên phải để tải về.
![](https://user-images.githubusercontent.com/100114917/169863797-3bf38b37-5d68-4ef0-86f8-961d5fa09eed.PNG)

B2:mở file GameWorld.rar chọn release.
![.](https://user-images.githubusercontent.com/100114917/169863916-2794df9a-8638-42ba-a46d-7de565b32722.PNG)

B3:Chọn SDL_Lession3 để chạy chương trình .
![.](https://user-images.githubusercontent.com/100114917/169863994-c13578fd-9c87-4fbb-9697-66da3ca52aad.PNG)

*Lưu ý: Bạn phải tải file gameworld.rar thì mới có file SDl_Lession3.exe. Trong google drive sẽ không có sắn.

#### **CÁC Ý TƯỞNG CHÍNH**



* **Ramdom các vật thể ngẫu nhiên:**

  - Xây dựng 1 class để sử lí 3 đối tượng bằng vector : xa chạy ngược chiểu Vector<Obstacle car>, chướng ngại vật trên đường Vector<obstacle object>, vật phẩm  Vector<object To buff power>. lớp này có chức năng là đẩy đối tưởng vào vector, xử lí vận tốc, render đối tượng ra màn hình.
  - Khi chương trình chạy ta đẩy các đối tượng được đẩy vào vector rồi render ra màn hình, khi đối tượng chạy quá chiều cao của màn hình nó sẽ bị xóa khỏi vector.

* **Xử lí va chạm.**

  - Mỗi vật thể ta sẽ có một cái khung hình chữ nhật bao quanh nó. Ta sẽ xét các trường hợp khi vật **không** xảy ra va chạm
    - Đáy A < Đỉnh B.
    - Đỉnh A > Đáy B.
    - Phải A < Trái B.
    - Trái A > phải B.

    -   **Lưu ý** : khi ta xét điều kiện ngược lại để xảy ra va chạm thì sẽ **không đúng**

* **Thay đổi màu sắc của xe khi ăn được vật phẩm.**

  - Ta sẽ tạo ra 1 đối tượng mainCar và 2  texture là 2 trạng thái khi được cường hóa sức mạnh khi không được cường hóa sức mạnh.
  - Khi ta kiểm tra điều kiện xảy ra va chạm với vận phầm ta sẽ có biến lưu thời gian tại thời điểm đó, ta xét lại trạng thái của xe khi hết thời gian quy ta đinh lại xét lại trạng thái ban đầu của nó.

#### **MÔ TẢ CHỨC NĂNG**



 Link mô tả: https://youtu.be/3o1E1h5qmh4

- **Hệ thống meneu với các nút chức năng.**
  - Nút play.
  - Nút option: giới thiệu, hướng dẫn chung về game. Nút này ta chỉ cần trỏ con chuột của mình tới vị trí của nút.
  - Nút Exit.
  - Nút Play again.
  - Nút pause : Nút này sử dụng khi ta ấn chuột và giữ thì lệnh này sẽ được thực thi
- **Hệ thống âm thanh vui nhộn, sinh động**.
  - Nhạc nền.
  - Nhạc hiệu ứng: khi ăn được vật phẩm, khi kết thúc game.
- **Tốc độ của xe sẽ tăng lên sau 35s.**
- **Hiệu ứng**
  - Khi xảy ra va chạm.
  - Hiệu ứng đổi màu mỗi khi xe ăn được vật phẩm.

#### **CÁC KĨ THUẬT LẬP TRÌNH ĐƯỢC SỬ DỤNG** .

- **Mảng thường, Mảng Vector.**
- **Con trỏ/giải phóng bộ nhớ.**
- **Class.**
- **Bắt sự kiện.**
- **Độ họa SDL.**
-  **Bắt va chạm hình chứ nhật.**
- **Đặt cờ.**
- **Sinh ngẫu nhiên số.**
- **Chia file.**
- **Các lớp đối tượng được sử dụng.**
  - class LTexture.
  - Class buttonMeneu.
  - Class CommomObject.
  - Class LTimer.
  - Class MainCar.
  - Class ObjectBuffPower.
  - Class ObstalceCar.
  - Class ObstacleObject.

#### **KẾT LUẬN,HƯỚNG PHÁT TRIỂN GAME, NHỮNG ĐIỀU TÂM ĐẮC.**

Qua quá trình làm game giúp cho bản thân các sinh viên học được nhiều về kĩ năng viết code, xử lí code, trình bày code, kĩ thuật tách file, khả năng tư duy, học được kiến thức mới về đồ họa, học được thêm nhiều kiến thức khác như github, photoshop, thuần thục hơn trong việc sử dụng class, cũng như khả năng kiên trì, tự tìm hiểu học hỏi, kĩ năng sử dụng google là những thứ mà lập trình viên phải có. Qua đó thấy việc học lập trình game nó cung cấp rất nhiều trang bị cần thiết cho sinh viên, giúp sinh viên hình dung sơ lược được 1 project được tổ chức thực thi như nào.

-  **Hướng phát triển game**

  - Bổ sung chức năng cho game
    - thêm vật phẩm bình xăng, khi chiếc xe di chuyển thì lượng xăng giảm dần và các bình xăng sẽ được render ngẫu nhiên trên đường, khi hết xăng bạn sẽ thua cuộc.
    - Thêm vật phẩm tăng sức mạnh, khi ăn được vật phẩm này, bạn sẽ trở nên vô địch và có khả năng húc hoặc bay qua các xe khác.
    - thêm các lựa chọn xe khác nhau khi bắt đầu chơi.
    - thêm khả năng di chuyển sang làn khác cho các xe chạy ngược chiều.
    - thêm nhiều và đa dang dạng các chướng ngại trên đường.
    - Chuyển màn: khi nhận được một số điểm nào đó, background sẽ thay đổi.
  - **Cải thiện đồ họa cho game.**
    - cải thiện lại cho các nút bầm xe, và các vật thể.
  - **Cải thiện về cách nhận điểm.**
    - Ta sẽ render ra các texture điểm ở các làn đường và khi xảy va chạm thì ta sẽ nhận được số điểm mà texture đó quy định.

- **Điều tâm đắc sau khi hoàn thiện game.**

  - Trong quá trình làm game điều tâm tắc đầu tiên của bản thân tôi là phần render random các đối tượng, và xử lí được va chạm cho các đối tượng sau nhiều lần thất bại.
  - điều thứ  2 là xử lí khi ăn vật phẩm xe thay đổi màu sắc xe của người chơi
  - Làm được 1 con game đơn giản mà trước khi học mình vẫn nghĩ mình sẽ không thể thực hiện được.
