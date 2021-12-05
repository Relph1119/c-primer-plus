# 模板代码

## 01 按行打印数组元素
```c
for (int i = 0; i < n; i++) {
    printf("%d%c", a[i], (i % 10 == 9 || i == n - 1) ? '\n' : '');
}
```

## 02 打印英语单词的复数形式
```c
printf("You have %d item%s.\n", n, n == 1 ? "" : "s");
```

## 03 二分查找
```c
int binsearch(int x, int v[], int n) {
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while(low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > x[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
```

## 04 shell排序
```c
void shellsort(int v[], int n) {
    int gap, i, j, temp;
    
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}
```

## 05 数组逆序
```c
void reverse(char s[]) {
    int c, i, j;
    
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
```

## 06 快速排序
```c
void qsort(int v[], int left, int right) {
    int i, last;
    void swap(int v[], int i, int j);
    
    if (left >= right) {
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (v[i] < v[left])
            swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(int v[], int i, int j) {
    int temp;
    
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
```