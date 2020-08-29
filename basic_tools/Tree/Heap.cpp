//堆是完全二叉树，每个父亲结点的权值都大于等于获小于等于其孩子结点
//完全二叉树可以用数组实现
const int maxn = 100;
int heap[maxn], n = 10;

//对heap数组[low, high]范围进行向下调整
void downAdjust(int low, int high){
    int i = low, j = 2 * i; //i为欲调整结点，2*i为其左孩子，2*i+1为其右孩子
    while(j <= high){
        if(j + 1 <= high && heap[j + 1] > heap[j]){
            j = j + 1;
        }
        if(heap[i] < heap[j]){
            swap(heap[i], heap[j]);
            i = j;
            j = 2 * i;
        }
        else{
            break; //若孩子结点权值都比该结点小，则调整结束
        }
    }
}

//建堆,保证每个结点都是以其为根节点的子树中权值最大的结点
void createHeap(){
    for(int i = n / 2; i >= 1; i--){ //遍历所有非叶子结点(1到[n/2]号)
        downAdjust(i, n);
    }
}

//删除堆顶元素
void deleteTop(){
    heap[1] = heap[n];
    n--;
    downAdjust(1, n);
}

//向上调整
void upAdjust(int low, int high){
    int i = high, j = i / 2; //i为欲调整结点，j为其父亲
    while(j >= low){
        if(heap[i] > heap[j]){
            swap(heap[i], heap[j]);
            i = j;
            j = i / 2;
        }
        else{
            break;
        }
    }
}

//添加元素x
void insert(int x){
    heap[++n] = x; //放到最后，向上调整
    upAdjust(1, n);
}

//堆排序
void heapSort(){
    createHeap();
    for(int i = n; i > 1; i--){
        swap(heap[i], heap[1]);
        downAdjust(1, i - 1);
    }
}