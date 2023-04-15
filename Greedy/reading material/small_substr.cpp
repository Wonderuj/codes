// string remove_k_digits(string num, int k)
// {
//     int n = num.length();
//     string ans;
//     stack<char> res;
//     int i;
//     for (i = 0; i < n; i++)
//     {
//         while (!res.empty() and res.top() > num[i] and k > 0)
//         {
//             k--;
//             res.pop();
//         }
//         res.push(num[i]);
//     }
//     while (!res.empty())                    
//     {
//         ans.push_back(res.top());                   
//         res.pop();
//     }
//     reverse(ans.begin(), ans.end());
//     while (k--)                                            //we are checking if the some k are still left and removing that number of elements form the start
//         ans.pop_back();
//     i = 0;
//     while (i < n and ans[i] == '0')
//         i++;
//     ans = ans.substr(i);                        //here we checked for inital trailing 0's on start and not printing it.
//     if (ans.empty())
//         return "0";
//     return ans;
// }

// /*
// 0 0 1 3 5 9 7  ,k=3
// 0 0 1 3 5 7 k left =2

// then processing it will delete 5 and 7 from loop at line 22
// 0 0 1 3
// then while loop at line 25 will remove starting 0's from ans
// and we will finally get 13 as ans. 
// and if string becomes empty we have to print 0 as string.
// */