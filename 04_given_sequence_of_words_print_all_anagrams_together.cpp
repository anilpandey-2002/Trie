class Solution
{
public:
    vector<vector<string>> anagrams(vector<string> &arr)
    {
        vector<vector<string>> result;

        unordered_map<string, vector<string>> umap;

        for (int i = 0; i < arr.size(); i++)
        {
            string s = arr[i];

            sort(s.begin(), s.end());

            umap[s].push_back(arr[i]);
        }
        for (auto itr = umap.begin(); itr != umap.end(); itr++)
            result.push_back(itr->second);

        return result;
    }
};