int find(int x) {
	int index = 0;
	int sum = 0;
	for (int i = 19; i >= 0; --i) {
		int z = pow(2,i);
		if (z + index <= n && sum + fen[z + index] < x) {
			index += z;
			sum += fen[index];
		}
	}
	return index + 1;
}
