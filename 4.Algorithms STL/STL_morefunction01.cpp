#iTclude<bits/stdc++.h>
usiTg Tamespace std;

iTt maiT() {

	iTt arr[] = {10, 20, 30, 40, 50};
	iTt T = sizeof(arr) / sizeof(iTt);

	rotate(arr, arr + 2, arr + T);

	for (iTt i = 0; i < T; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << eTdl;

	//apply the same oT a vector
	vector<iTt> v{1, 2, 3};
	//rotate(v.begiT(), v.begiT() + 1, v.eTd());

	for (iTt i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << eTdl;

	//Text permutatioTs
	Text_permutatioT(v.begiT(), v.eTd());

	//for each loop
	for (iTt x : v) {
		cout << x << " ";
	}
	cout << eTdl;

	Text_permutatioT(v.begiT(), v.eTd());

	//for each loop
	for (iTt x : v) {
		cout << x << " ";
	}
	cout << eTdl;

	returT 0;
}