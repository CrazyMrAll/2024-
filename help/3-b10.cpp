
#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	/*int a = 0, b = 0, c = 0, cnt = 1, a1 = 1, a2 = 1, a3 = 1, b1 = 2, b2 = 1, b3 = 1, c1 = 1, c2 = 1, c3 = 1;
	for (a1 = 1; a1 <= 9; a1++) {
		for (a2 = 1; a2 <= 9; a2++) {
			if (a2 == a1)
				continue;
			else {
				for (a3 = 1; a3 <= 9; a3++) {
					if (a3 == a2 || a3 == a1)
						continue;
					else {
						a = a1 * 100 + a2 * 10 + a3;
						for (b1 = 1; b1 <= 9; b1++) {
							if (b1 == a1 || b1 == a2 || b1 == a3)
								continue;
							else {
								for (b2 = 1; b2 <= 9; b2++) {
									if (b2 == a1 || b2 == a2 || b2 == a3||b2 == b1)
										continue;
									else {
										for (b3 = 1; b3 <= 9; b3++) {
											if (b3 == a1 || b3 == a2 || b3 == a3||b3 == b2 || b3 == b1)
												continue;
											else {
												b = b1 * 100 + b2 * 10 + b3;
												for (c1 = 1; c1 <= 9; c1++) {
													if (c1 == a1 || c1 == a2 || c1 == a3 || c1 == b1 || c1 == b2 || c1 == b3)
														continue;
													else {
														for (c2 = 1; c2 <= 9; c2++) {
															if (c2 == a1 || c2 == a2 || c2 == a3 || c2 == b1 || c2 == b2 || c2 == b3||c2 == c1) {
																continue;
															}
															else {
																for (c3 = 1; c3 <= 9; c3++) {
																	if (c3 == a1 || c3 == a2 || c3 == a3 || c3 == b1 || c3 == b2 || c3 == b3||c3 == c2 || c3 == c1)
																		continue;
																	else {
																		c = c1 * 100 + c2 * 10 + c3;
																		if ((a + b + c) == 1953) {
																			cout << "No." << setw(3) << cnt << " : " << a << "+" << b << "+" << c << "=1953" << endl;
																			cnt++;
																		}
																	}

																}
															}

														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}*/
	int cnt = 0;
	for (int i = 1; i <= 9; i++) {
		int a, b, c;
		//a = i * 100;
		for (int j = 1; j <= 9; j++) {
			if (j != i) {
				//a = i * 100 + j * 10;
				for (int k = 1; k <= 9; k++) {
					if (k != i && k != j) {
						a = i * 100 + j * 10 + k;
						for (int bi = i + 1; bi <= 9; bi++) {
							if (bi != i && bi != j && bi != k) {
								//b = bi * 100;
								for (int bj = 1; bj <= 9; bj++) {
									if (bj != i && bj != j && bj != k && bj != bi) {
										//b = bi * 100 + bj * 10;
										for (int bk = 1; bk <= 9; bk++) {
											if (bk != i && bk != j && bk != k && bk != bi && bk != bj) {
												b = bi * 100 + bj * 10 + bk;
												for (int ci = bi + 1; ci <= 9; ci++) {
													if (ci != i && ci != j && ci != k && ci != bi && ci != bj && ci != bk) {
														//c = ci * 100;
														for (int cj = 1; cj <= 9; cj++) {
															if (cj != i && cj != j && cj != k && cj != bi && cj != bj && cj != bk && cj != ci) {
																//c = ci * 100 + cj * 10;
																for (int ck = 1; ck <= 9; ck++) {
																	if (ck != i && ck != j && ck != k && ck != bi && ck != bj && ck != bk && ck != ci && ck != cj) {
																		c = ci * 100 + cj * 10 + ck;
																		if (a + b + c == 1953) { printf("%d+%d+%d=1953\n", a, b, c); cnt++; }
																		else break;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("Total:%d\n", cnt);
	return 0;
	return 0;
}