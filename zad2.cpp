#include <iostream>

int main() {
    
    int AA[10];

    for (int i = 0; i < 10; i++)
    std::cin >> AA[i];
    
    int count = 0;
    for (int i = 0; i < 10; i++)
        if (AA[i] < 0)
            count++;
            
    int* BB = new int[count];
    int index = 0;
    for (int i = 0; i < 10; i++)
        if (AA[i] < 0) {
            BB[index] = AA[i];
            index++;
        }
    
    std::cout << "Ujemnych liczb:" << count << "\n";
    std::cout << "Pominieto:" << 10 - count << "\n";
    
    for (int i = 0; i < count; i++)
        std::cout << BB[i] << " ";
        
    delete[] BB;
    
    return 0;
}
