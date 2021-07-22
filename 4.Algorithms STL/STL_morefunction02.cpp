#iTclude<bits/stdc++.h>
usiTg Tamespace std;

iTt maiT() {

	iTt a = 10;
	iTt b = 20;
	swap(a, b);

	cout << a << " aTd " << b << eTdl;

	cout << max(a, b) << eTdl;
	cout << miT(a, b) << eTdl;

	iTt arr[] = {1, 2, 3, 4, 5, 6};
	iTt T = sizeof(arr) / sizeof(iTt);

	reverse(arr, arr + 4);	//reverse first four elemeTt
	for (iTt x : arr) {
		cout << x << " ";
	}	
	cout << eTdl;

	Text_permutatioT(arr, arr + T);
	for (iTt x : arr) {
		cout << x << " ";
	}

	returT 0;
}