


# 42_push_swap

```
gcc -v
Apple clang version 12.0.0 (clang-1200.0.32.29)
```
## what is push_swap ?
2つの異なるスタックAとBを用いて、引数として与えられた数（重複なし）をあるルールに従ってソートするプログラム。

`sa`はスタックAの先頭と二番目を入れ替える。

`sb`はスタックBの先頭と二番目を入れ替える。

`ss`は`sa`と`sb`を同時に行う。

`ra`はスタックAの先頭を末尾に移動。

`rb`はスタックBの先頭を末尾に移動。

`rr`は`ra`と`rb`を同時に行う。

`rra`はスタックAの末尾を先頭に移動。

`rrb`はスタックBの末尾を先頭に移動。

`rrr`は`rra`と`rrb`を同時に行う。

`pa`はスタックBの先頭をスタックAの先頭にする。


`pb`はスタックAの先頭をスタックBの先頭にする。

`./push_swap`は引数をソートするのに必要な命令を出力する
`./checker`は`./push_swap`によって出力された命令を入力し、正しくソートが完了したか確認する。


## Usage
```c
$ make 
$ ./push_swap 5 4 3 2 1   //randam number
$ rra
$ pb
$ rra
$ pb
$ sa
$ rra
$ pa
$ pa

$ ./checker 5 4 3 2 1
$ rra
$ pb
$ rra
$ pb
$ sa
$ rra
$ pa
$ pa
$ OK
```

### Any options
```c
//-v option is visual mode
$ ./push_swap -v 44 33 5 1 0 -1  99 //randam number
```
https://user-images.githubusercontent.com/60804160/117639390-d3306980-b1be-11eb-8431-2427987f5eba.mp4

```c
//-a option is after sort
$ ./push_swap -a 1111 4444444 33323 554 5654 //randam number
```

```c
//-c option is command counts
$ ./push_swap -c 1111 4444444 33323 554 5654 //randam number
```
You can use all options
```c
$./push_swap -vac 9 4 3 2 8 5 100 99 44 
```
