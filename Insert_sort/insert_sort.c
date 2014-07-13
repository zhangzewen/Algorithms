void insert_sort(int *array, unsigned int n)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 1; i < n; i++) {
		if (array[i] < array[i - 1]) {
			tmp = array[i];
			array[i] = array[i - 1];
			for (j = i - 1; j >=0 && tmp < array[j]; --j) {
				array[j + 1] = array[j];
			}
			array[j + 1] = tmp;
		}
	}
}

int main(int argc,  char *argv[])
{
	int a[] = {9, 10, 7, 6, 15,4,32,2,1,0};
	insert_sort(a, 10);
}
