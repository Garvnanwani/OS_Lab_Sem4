#include<bits/stdc++.h>
using namespace std;

void First_Fit(int block_size[], int total_blocks, int process_size[], int total_process) {
   int allocation[total_process];
   memset(allocation, -1, sizeof(allocation));
   for (int i = 0; i < total_process; i++) {
      for (int j = 0; j < total_blocks; j++) {
         if (block_size[j] >= process_size[i]) {
            allocation[i] = j;
            block_size[j] -= process_size[i];
            break;
         }
      }
   }
   cout << "\nProcess No.\tProcess Size\tBlock no.\n";
   for (int i = 0; i < total_process; i++) {
      cout << " " << i+1 << "\t\t" << process_size[i] << "\t\t";
      if (allocation[i] != -1)
         cout << allocation[i] + 1;
      else
         cout << "Not Allocated";
         cout << endl;
   }
}
int main() {
   int total_blocks,total_process;
    cout << "Enter Number of Memory Blocks\n";
    cin >> total_blocks;
    cout << "Enter Number of Process\n";
    cin >> total_process;

   int block_size[total_blocks], process_size[total_process];
   cout << "Enter values of Memory Blocks\n";
   for (int i = 0; i < total_blocks; i++) {
       cin >> block_size[i];
   }
   cout << "Enter values of Process\n";
   for (int i = 0; i < total_process; i++) {
       cin >> process_size[i];
   }
   First_Fit(block_size, total_blocks, process_size, total_process);
   return 0 ;
}
