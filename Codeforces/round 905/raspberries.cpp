// I learnt from a solution that  (k - x % k) % k) will directly give how much further it is from next multiple.
/*
 * author:  magnus_hegdahl
 * created: 02.11.2023 00:40
 * problem: C. Raspberries
 * url:     https://codeforces.com/contest/1883/problem/C
#include <iostream>
#include <vector>

// <ints.hpp>
#include <cstddef>
#include <cstdint>
using i8 = std::int8_t;
using u8 = std::uint8_t;
using i16 = std::int16_t;
using u16 = std::uint16_t;
using i32 = std::int32_t;
using u32 = std::uint32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;
#ifdef __SIZEOF_INT128__
using i128 = __int128_t;
using u128 = __uint128_t;
#endif
using isize = std::ptrdiff_t;
using usize = std::size_t;
// </ints.hpp>

auto main() -> int
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    usize test_count;
    std::cin >> test_count;
    for (usize test_id = 0; test_id != test_count; ++test_id)
    {
        usize n;
        u32 k;
        std::cin >> n >> k;
        auto a = std::vector<u32>(n);
        for (u32 &x : a)
            std::cin >> x;

        u32 ans = k;
        for (u32 x : a)
            ans = std::min(ans, (k - x % k) % k);

        if (k == 4)
        {
            u32 evens = 0;
            for (u32 x : a)
            {
                evens += x % 2 == 0;
            }

            ans = std::min(ans, 2 - std::min(evens, 2u));
        }

        std::cout << ans << '\n';
    }
}

*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    // sort(arr.begin(), arr.end());
    vector<int> table;
    int maxi = 100100;

    for (auto x : arr)
    {
        if (x % k == 0)
        {
            cout << 0 << endl;
            return;
        }
    }

    for (int i = k; i < maxi; i += k)
    {
        table.push_back(i);
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        int x = *lower_bound(table.begin(), table.end(), arr[i]);
        ans = min(x - arr[i], ans);
    }

    if (k == 4)
    {
        int evens = 0;
        for (auto x : arr)
        {
            if (x % 2 == 0)
                evens++;
        }
        if (evens > 2)
            ans = 0;
        else
            ans = min(2 - evens, ans);
    }

    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t;
    cin >> _t;
    while (_t--)
        solve();
}