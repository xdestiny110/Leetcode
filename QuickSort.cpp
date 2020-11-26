#include <iostream>
#include <vector>

void quickSort(int left, int right, std::vector<int>& arr){
    if(left >= right)
		return;
	int l = left, r = right;
	//取最左边的数为基准数
	while (l < r)
	{
		while (l < r && arr[r] >= arr[left]) r--;
		while (l < r && arr[l] <= arr[left]) l++;
		if(l < r) std::swap(arr[l], arr[r]);
	}
    std::swap(arr[l], arr[left]);
	quickSort(left, l - 1, arr);
	quickSort(l + 1, right, arr); 
}

int main(int argc, char** argv){
    std::vector<int> arr = {2,4,1,8,6,3,11,9};
    quickSort(0, arr.size() - 1, arr);
    for(const auto& it : arr){
        std::cout << it << std::endl;
    }
}