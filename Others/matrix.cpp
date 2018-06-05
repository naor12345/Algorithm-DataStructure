// 矩阵定义
// template <class T>
struct Matrix
{
    int *data;
    int width;
    int height;
    Matrix():data(NULL), width(0), height(0){}
    Matrix(int w, int h): width(w), height(h)
    {
        data = new int[width * height];
    }
    ~Matrix()
    {
        delete []data;
    }
    Matrix(const Matrix &a)
    {
        width = a.width;
        height = a.height;
        if(a.data != NULL)
        {
            data = (int*)malloc(width * height * sizeof(int));
            memcpy(data, a.data, width*height*sizeof(int));
        } 
    }
};

// 打印矩阵
void printMatrix(Matrix &m)
{
    if(m.data == NULL)
    {
        return;
    }

    for(int i = 0; i<m.height; i++)
    {
        for(int j = 0; j<m.width; j++)
        {
            printf("%d ", m.data[i * m.width + j]);
        }
        printf("\n");
    }
}


// 矩阵乘法
// b = a1 * a2
Matrix multiMatrix(Matrix &a1， Matrix &a2)
{
    if(a1.data == NULL || a2.data == NULL) assert(false);
    Matrix b = 
    if(b.data == NULL) {
        b.data = new int[a1.height * a2.width];
        b.width = a2.width;
        b.height = a1.height;
    }

    for(int i = 0; i<a1.height; i++)
    {
        for(int j = 0; j<a2.width; j++)
        {
            for(int k = 0; k<a1.width; k++)
            {
                b.data[i * b.width + j] = a1.data[i * a1.width + k]
                                        * a2.data[k * a2.width + j];
            }
        }
    }
}

// 矩阵乘方
// a^p = b
void matrixPower(Matrix &a, int p, Matrix &b)
{
    if(a.width == 0 || a.width != a.height)
    {
        assert(false);
    }

    if(b.data == NULL)
    {
        b.data = new int[a.width * a.height];
        b.width = a.width;
        b.height = a.height;
    }

    memset(b.data, 0, b.width * b.height * sizeof(int));
    for(int i = 0; i<b.width; i++)
    {
        b.data[i * b.width + i] = 1;
    }

    Matrix tmp(b.width, b.height);
    for(; p!=0; p>>=1)
    {
        if(p & 1)
        {
            multiMatrix(b, tmp, b);
        }
        tmp = multiMatrix(tmp, tmp, tmp)
    }
}