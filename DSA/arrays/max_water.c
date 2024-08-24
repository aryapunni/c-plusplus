# include<stdio.h>

void print_array(int * array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}


void max_water(int * array, int size)
{

    int area = 0;
    int max_val = 0;
    int hight = 0;
    int width = 0;
    int index_array[2] = {0};

    print_array(array, size);
    for(int i=0; i<size; i++)
    {
        printf("i: %d\n", i);
        for(int j = i + 1;j < size; j++)
        {

            width = j - i;

            if(array[i] > array[j]) {
                hight = array[j];
            } else {
                hight = array[i];
            }
            area = width * hight;

            if(area > max_val)
            {
                max_val = area;
                
            }

            printf("height: %d width: %d max_val: %d\n", hight, width, max_val);

        }
        printf("\n");
    }
    printf("max_val: %d\n", max_val);
}

int main(void)
{
    int array[] = {2, 4, 8, 4, 4, 9};
    max_water(array, sizeof(array)/sizeof(int)); 

    return 0;
}





