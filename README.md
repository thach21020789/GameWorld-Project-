# GameWorld

- **Đinh Văn Thạch**: 21020789

- **Lớp**: K66CD-CN1-UET.

- **Môn học**: Lập trình nâng cao(INT2215_1), Nhóm: 9

- **Email**: 21020789@vnu.edu.vn

## Mục lục

1. **Giới thiệu chung.**
2. **Cách cài đặt.**
3. **Các ý tưởng chính.**
4. **Mô tả chức năng.**
5. **Các kĩ năng lập trình được sử dụng.**
6. **Kết luận, hướng phát triển game, điều tâm đắc.**
7. **Điều tâm đắc**

## **1.Giới thiệu chung**

**GameWorld** được phát triển dựa trên tựa game đua xe cổ điển né chướng ngại vật và các xe chạy ngược chiều với nó.

**Luật chơi:**

- **Người chơi điều khiển chiếc xe né các chướng ngại vật trên đường và các xe cộ chạy trên đường, tránh những va chạm trên đường.**
  - Nhấn UP để di chuyển lên trên.
  - Nhấn DOWN để di chuyển xuống.
  - Nhấn LEFT để di chuyển sang trái.
  - Nhấn RIGHT để di chuyển sang phải.
- **Điểm của người chơi chính bằng số giây từ lúc bắt đầu chơi đến lúc xảy ra va chạm.**
- **Khi càng lên cao số vàng bạn nhận được sẽ nhiều hơn,  đồng nghĩa với  đó là sẽ có nhiều thử thách hơn cho bạn đó nhá.**
- **Khi chơi người chơi có thể ăn các vật phẩm ở trên đường đi để cướng hóa sức mạnh cho chiếc xe.**

## 2.Cách cài đặt

**Tải xuống tại đây:** [download](https://drive.google.com/file/d/1gFqIGVLQyj48KNJ8iiak9ttDFzPoSgxC/view?usp=sharing)

**Bước 1**: Sau khi truy cập vào link click vào góc bên phải để tải về.
![](https://user-images.githubusercontent.com/100114917/169863797-3bf38b37-5d68-4ef0-86f8-961d5fa09eed.PNG)

**Bước 2**:  mở file GameWorld.rar chọn release.
![.](https://user-images.githubusercontent.com/100114917/169863916-2794df9a-8638-42ba-a46d-7de565b32722.PNG)

**Bước 3**: Chọn GameWorld.exe để chạy chương trình.

![.](https://user-images.githubusercontent.com/100114917/170213304-0115f488-4151-454b-8b87-1e5b843fd151.PNG)

***Lưu ý:** Bạn phải tải file gameworld.rar thì mới có file GameWorld.exe. Trong google drive sẽ không có sẵn.

## 3.Các ý tưởng chính



* **Ramdom các vật thể ngẫu nhiên:**
  - Xây dựng 1 class để sử lí 3 đối tượng bằng vector : xa chạy ngược chiểu Vector<Obstacle car>, chướng ngại vật trên đường Vector<obstacle object>, vật phẩm  Vector<object To buff power>. lớp này có chức năng là đẩy đối tưởng vào vector, xử lí vận tốc, render đối tượng ra màn hình.
  - Khi chương trình chạy ta đẩy các đối tượng được đẩy vào vector rồi render ra màn hình, khi đối tượng chạy quá chiều cao của màn hình nó sẽ bị xóa khỏi vector.
  
* **Xử lí va chạm.**
  - Mỗi vật thể ta sẽ có một cái khung hình chữ nhật bao quanh nó. Ta sẽ xét các trường hợp khi vật **không** xảy ra va chạm
    - Đáy A < Đỉnh B.
    - Đỉnh A > Đáy B.
    - Phải A < Trái B.
    - Trái A > phải B.
  
  [.](https://user-images.githubusercontent.com/100114917/171033671-f4de92c9-f9a5-47a1-b4c0-d7ecc78f51d0.PNG)
  
    -   **Lưu ý** : khi ta xét điều kiện ngược lại để xảy ra va chạm thì sẽ **không đúng**
  
* **Thay đổi màu sắc của xe khi ăn được vật phẩm.**
  - Ta sẽ tạo ra 1 đối tượng mainCar và 2  texture là 2 trạng thái khi được cường hóa sức mạnh khi không được cường hóa sức mạnh.
  - Khi ta kiểm tra điều kiện xảy ra va chạm với vận phầm ta sẽ có biến lưu thời gian tại thời điểm đó, ta xét lại trạng thái của xe khi hết thời gian quy ta đinh lại xét lại trạng thái ban đầu của nó.

## **4.Mô tả chức năng:**

**Link Youtube mô tả**: https://youtu.be/3o1E1h5qmh4

**Hệ thống menu với các nút chức năng:**

- **Màn hình Menu:**
  - Nút play.
  - Nút option: giới thiệu, hướng dẫn chung về game. Nút này ta chỉ cần trỏ con chuột của mình tới vị trí của nút.
  - Nút Exit.

- **Màn hình pause:**
  -  Nút pause : Nút này sử dụng khi ta ấn chuột và giữ thì lệnh này sẽ được thực thi
  - Nút exit: Thoát ra màn hình menu
- **Màn hình Game over:**
  -  Nút Play again: Nút này sử dụng để chơi lại màn mới.

- **Hệ thống âm thanh vui nhộn, sinh động**:
  - Nhạc nền.
  - Nhạc hiệu ứng: khi ăn được vật phẩm, khi kết thúc game.
- **Tốc độ của xe sẽ tăng lên sau 35s**:
- **Hiệu ứng:**
  - Khi xảy ra va chạm.
  - Hiệu ứng đổi màu mỗi khi xe ăn được vật phẩm.

## **5.Các kĩ thuật lập trình được sử dụng:

- **Mảng thường, Mảng Vector.**
- **Con trỏ/giải phóng bộ nhớ.**
- **Class.**
- **Bắt sự kiện.**
- **Độ họa SDL.**
- **Bắt va chạm hình chứ nhật.**
- **Đặt cờ.**
- **Sinh ngẫu nhiên số.**
- **Chia file.**
- **Các lớp đối tượng được sử dụng.**
- **Sử dụng thư viện đồ họa SDL2, SDL2 image, SDL2 mixer, SDL2 ttf.**
  - Class **LTexture:**
    - LoadFromFile(): Tải một ảnh từ một 1 file lưu trữ đến Texture.
    - loadFromRenderedText(): Tải 1 file chữ thành chữ.
    - render(): Hiện thi hình ảnh lên màn hình.
    - Free(): giải phóng dữ liệu.
    - getRect(): Lấy hình hộp bao quanh một Texture.
    - getTexture(): Lấy ra Texture hiện tại.
    - SetTexture (): set Texture  mình muốn lấy ra.
  - Class **button:**
    - handleButton(): Kiểm tra điều kiện khi ta trỏ vào nút hay chưa.
    - LoadButton(): Load file ảnh của các nút.
    - renderButton(): Hiện thị các nút ra màn hình.
    - setIsButtonUseInScreen(): Xét bật tắt các nút.
    - setIsButtonClick(): Xét xem đã click vào nút chưa.
    -  setButtonRect(): Khợi tạo vi trí các nút .
    - setButtonClipOut():  ảnh khi chưa trỏ chuột tới.
    - setButtonClipOver(): ảnh khi ta vừa click xong thả lên.
    - setButtonClipDown(): Xét ảnh khi ta ấn chuột.
    - getIsButtonClick(): Lấy ra trạng thái có đang click chuột vào nút hay không.
  - Class **Menu:**
    - loadButtonTexture(): Tải ảnh chưa các nút và xét clip cho nó.
    - handleMenu() : Xét điều kiện khi ta click vào từng nút.
    - renderMenu(): Hiện thi từng nút ra màn hình.
    - renderBackground() : Render background của menu ở các trạng thái: trạng thái chờ, background cho nút Option và background của nút pause.
    - loadMenuBackdground() : Tải lên background của từng trạng thái.
    - setStartScreen() : Trạng thái bất tắt các nút ở màn hình chờ.
    - setPlayingScreen(): Trạng thái bật tắt các nút khi ta đang chơi game.
    - setPauseScreen(): Trạng thái bật tắt các nút ở trạng thái tạm dừng.
    - setOptionScreen() : trạng thái các nút khi ta chọn nút Option.
    - setPlayAgainScreen(): trạng thái các nút khi ở màn hình chờ play again.
    - setExplosionPositon(): Lấy tọa độ x,y của hiệu ứng nổ.
    - getScreenStatus(): Lấy ra trạng thái của màn hình.
  - Class **CommomObject:**
    - LoadObstacleCar(): Tải hình ảnh từ file của các xe chạy ngược chiều.
    - HandleObstaclecarList(): xử lí vận tốc của xe.
    - RenderObstaclecarList(): Hiện thi các xe chạy ngược chiều lên màn hình.
    - GetListObstacleCar(): lấy ra danh sách các xe chạy ngược chiều .
    - LoadObstacleObject(): Tải hình ảnh từ file của các chướng ngại vật(trừ xe) chạy ngược chiều.
    - HandleObstacleObject(): xử lí vận tốc của chướng ngại vật.
    - RenderObstacleObject(): hiện thi các chướng ngại vật ra màn hình.
    - get_ListObstacleObject(): lấy ra danh sách các chướng ngại vật chạy ngược chiều.
    - LoadObjectToBuffPower(): Tải các hình file để lưu Texture.
    - HandleObstacleListObjectToBuffPower(): Xử lí vận tốc cho các item cường hóa sức mạnh
    - RenderObstacleListObjectToBuffPower():  hiện thi các item cường hóa sức mạnh ra màn hình.
    - GetListObjectToBuffPower(): lấy ra danh sách các item.
    - ClearObstacleCar(): Xóa hết các xe chạy ngược chiều khi đi hết màn hình.
    - clearListObstacleObject():  Xóa hết các chướng ngại vật khi đi hết màn hình.
    - clearListObjectToBuffPower(): xóa các item.
    - increaseHardMode(): Tăng chỉ số của mảng vận tốc  cảu các xe chạy ngược chiều.
    - resetHardMode(): Chỉ số của mảng vận tốc quay về ban đầu.
  - Class **LTimer:**
    - start(): Khởi tạo thời gian.
    - stop(): Dừng thời gian lại, thời gian quay trở về 0.
    - pause(): tạm dừng thời gian.
    - unpause(): thời gian tiếp tục chạy sau khi bị tạm dừng.
    - getTicks(): Đồng hồ thời gian.
    - isStarted(): Kiểm tra trạng thái của đồng hồ có đang bắt đầu hay không.
    - isPaused(): kiểm tra trạng thái xem đồng hồ có đang tạm dừng không.
  - Class **MainCar:**
    - init(): Khởi tạo vị trí của xe và vị trí của hộp bao quanh nó (Khi muốn chơi màn mới).
    - SetStartPositionMainCar(): Khởi tạo vị trí ban đầu cho xe.
    - LoadMainCar(): Load dữ liệu của xe để lưu vào Texture.
    - SetCurrentTexture(): Lấy ra Texture mà ta muốn lấy ra.
    - HandleMainCar(): Xử lí di tọa độ của xe.
    - move(): Xử lí di chuyển của xe.
    - GetMainCarCollisionBoxOfMainCAr(): Lấy ra hình hộp xung quanh texture để kiểm tra va chạm.
  - Class **ItemToBuffPower:**
    - ​	SetStatrtPositionOfObjectBuffPower(): Khởi tạo vị trí cho các item cường hóa sức mạnh cho xe.
    - LoadObjectTobuffPower(): Tải hình ảnh các item từ file .
    - AutoIncreaseYForObjectBuffPower(): tăng vận tốc của các item.
    - ObjectBuffPowernotMove(): các item dừng di chuyển.
    - render(): hiển thị các hình ảnh item ra màn hình.
    - GetPositionYofObjectBuffPower(): Lấy tọa độ theo trục Y của các item.
    - GetBoxRect(): Lấy ra hình bên ngoài bao quanh item.
  - Class **ObstalceCar:**
    - SetStartPosionOfObstacleCar() : Khởi tạo vị trí của các xe và hộp xung quanh của các xe chạy ngược chiều.
    - LoadObstacleCar(): Tải dữ liệu xe để lưu vào Texture.
    - AutoIncreaseY(): Tăng vận tốc cho xe.
    - ObstacleCarNotMove(): Làm cho các xe không di chuyển.
    - render(): Tải các hình ảnh xe ra màn hình.
    - GetObstacleCarPosY(): Lấy vị trí theo trục Y của các xe chạy ngược chiều.
    - GetObstacleCarRect_box(): Lấy ra hộp bao quanh các xe để check va chạm.
  - Class **ObstacleObject:**
    - SetStartPosition(): xét vị trí cho các chướng ngại vật trên đường (trừ xe).
    - LoadObstacleObject_texture(): tải các hình ảnh chướng ngại vật từ file để lưu vào texture.
    - AutoIncreaseYForOstacleObject(): Cộng vận tốc theo trục Y của các chướng ngại vật.
    - ObjectNotMove(): Cho các chướng ngại vật dừng lại.
    - render(): Hiện thi các chướng ngại vật ra màn hình.
    - GetObjectPositionY(): Lấy tọa độ của các chướng ngại vật.
    - getObstacleObjectRect(): Lấy hình bao quanh của chướng ngại vật để kiểm tra va chạm.

## 6.Kết luận, hướng phát triển, điều tâm tắc.

​	Qua quá trình làm game giúp cho bản thân các sinh viên học được nhiều về kĩ năng viết code, xử lí code, trình bày code, kĩ thuật tách file, khả năng tư duy, học được kiến thức mới về đồ họa, học được thêm nhiều kiến thức khác như github, photoshop, thuần thục hơn trong việc sử dụng class, cũng như khả năng kiên trì, tự tìm hiểu học hỏi, kĩ năng sử dụng google là những thứ mà lập trình viên phải có. Qua đó thấy việc học lập trình game nó cung cấp rất nhiều trang bị cần thiết cho sinh viên, giúp sinh viên hình dung sơ lược được 1 project được tổ chức thực thi như nào.

-  **Hướng phát triển game**

  - Bổ sung chức năng cho game
    - Thêm vật phẩm bình xăng, khi chiếc xe di chuyển thì lượng xăng giảm dần và các bình xăng sẽ được render ngẫu nhiên trên đường, khi hết xăng bạn sẽ thua cuộc.
    - Thêm vật phẩm tăng sức mạnh, khi ăn được vật phẩm này, bạn sẽ trở nên vô địch và có khả năng húc hoặc bay qua các xe khác.
    - Thêm các lựa chọn xe khác nhau khi bắt đầu chơi.
    - Thêm khả năng di chuyển sang làn khác cho các xe chạy ngược chiều.
    - Thêm nhiều và đa dang dạng các chướng ngại trên đường.
    - Chuyển màn: khi nhận được một số điểm nào đó, background sẽ thay đổi.
  - **Cải thiện đồ họa cho game.**
    - Cải thiện lại cho các nút bầm xe, và các vật thể.
  - **Cải thiện về cách nhận điểm.**
    - Ta sẽ render ra các texture điểm ở các làn đường và khi xảy va chạm thì ta sẽ nhận được số điểm mà texture đó quy định.

- **Điều tâm đắc sau khi hoàn thiện game.**
  - Trong quá trình làm game điều tâm tắc đầu tiên của bản thân tôi là phần render random các đối tượng, và xử lí được va chạm cho các đối tượng sau nhiều lần thất bại.
  - Điều thứ  2 là xử lí khi ăn vật phẩm xe thay đổi màu sắc xe của người chơi
  - Làm được 1 con game đơn giản mà trước khi học mình vẫn nghĩ mình sẽ không thể thực hiện được.

#### LỜI CẢM ƠN:

**Special thanks to:**	

- Thầy Trần Quốc Long
- Thầy Nguyễn Việt Anh
- Thầy Nguyễn Hoàng Minh Công

Đã giúp em hoàn thành bài tập này.

