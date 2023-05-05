"""
Problem: Maximum Distance
Link: https://codeforces.com/gym/102951/problem/A
Tags: Brute force
Explaination:
We will try every possible combination of two points

Complexity: O(n^2)
"""


n = int(input())
x = list(map(int,input().strip().split()))[:n]
y = list(map(int,input().strip().split()))[:n]
sol = 0
for i in range(n):
	for j in range(i, n):
		dx = x[i] - x[j]
		dy = y[i] - y[j]
		sol = max(sol, dx*dx + dy*dy)
print(sol)

# Solved by: Muaath Alqarni