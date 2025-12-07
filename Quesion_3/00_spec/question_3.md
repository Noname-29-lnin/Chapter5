Câu 3: Cho giải đoạn code C sau:

```C
    for(int i = 0; i <= n-1; i++){
        smallest = i;
        for(int j = i+1; j <= n; j++){
            if(arr[j] < arr[Smallest]){
                Smallest = j;
                swap(arr[i], arr[Smallest]);
            }
        }
    }
```

Giả sử dữ liệu được lưu trong một bộ nhớ SinglePort với quá trình đọc/ghi diễn ra đồng bộ theo Clk và hoàn thành trong 1 Clk.

1. Định nghĩa ngõ vào và ra của thiết kế, vẽ kết nối của thiết kế với bộ nhớ (yêu cầu phải có chân start vaf reset).
2. Thiết kế máy trạng thái bậc cao của thiết kế.
3. Thiết kế Datapath và ControlUnit của thiết kế.
4. Viết chương trình mô phỏng hoạt động của thiết kế.
5. Giả sử vòng lặp i=0, không có swap và vòng lặp i=1, có swap. Vẽ dạng sóng từ lúc start=1 đến lúc hoàn thành vòng lặp i=1 của thiết kế.

Viết lại hàm C trên có một số lỗi sai:

```C
    for(int i = 0; i <= n-1; i++){
        min = i;
        for(int j = i+1; j <= n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
```