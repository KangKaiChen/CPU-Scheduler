# CPU-Scheduler

讀入一份包含所選擇的排程法 時間片段以及CPU的ID   CPU Burst  Arrival Time   Priority 在依照各個排程法所定義的次序依序排程，最後會輸出該排程法得到的甘特圖 以及 每個process在做完的等待時間(waiting time ) 往返時間( Turnarround time ) 另外甘特圖的 id if > 9 會使用英文字母代替 ex A = 10, B = 11 以此類推

1.	處理原則 – FCFS
2.	處理原則 – RR
3.	處理原則 – SRTF
4.  處理原則 – PPRR
5.  處理原則 – HRRN


INPUT檔
![image](https://user-images.githubusercontent.com/55120331/135711834-ee4e3f6d-2fb7-4251-837c-222fae37b25e.png)
MODE (1~6)
1.FCFS
2.RR
3.SRTF
4.PPRR
5.HRRN
6.ALL ( 以上五種都要請依順序輸出 )

OUTPUT檔

ID為0-9，A-Z，若該時間沒有process在執行由減號 (-)代表
由10開始為A依序向下代表，總共process id 不會超過36\個
Method 輸出順序 FCFS RR SRTF PPRR HRRN 第二個區段顯示各個 process id 在各個 method(可能數個 )的 Waiting Time 第三個區段顯示各個 process id 在各個 method(可能數個 )的 Turn around Time
詳細

![image](https://user-images.githubusercontent.com/55120331/135711874-34cae683-e2a8-4e82-b731-0a26041bb24e.png)
