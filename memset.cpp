#include<iostream>
#include<cstring>

int main(int argc, char const *argv[])
{
    int arr[10] = {0};

    for(int i=0; i<10; i++)
        std::cout << arr[i] << " ";
    
    std::cout << std::endl;

    std::memset(arr, 0, sizeof(arr));

    for(int i=0; i<10; i++)
        std::cout << arr[i] << " ";

    return 0;
}
