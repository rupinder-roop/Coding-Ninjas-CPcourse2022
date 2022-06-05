typedef struct Node
{
	Node *next[26];
	int maxSubtree;
	Node()
	{
		maxSubtree = 0;
		for (int i = 0; i < 26; i++)
			next[i] = NULL;
	}~Node()
	{
		for (int i = 0; i < 26; i++)
		{
			if (next[i] != NULL)
			{
				delete next[i];
			}
		}
	}
}

Node;
void insert(Node *curr, pair<string, int> &databaseEntry, int index)
{
	// Setting the Priority of the current text.
	if (index == databaseEntry.first.length())
	{
		curr->maxSubtree = databaseEntry.second;
		return;
	}

	curr->maxSubtree = max(curr->maxSubtree, databaseEntry.second);
	// Getting the next character.
	int nextIndex = (int)(databaseEntry.first[index] - 'a');
	// Creating a new node in Trie.
	if (curr->next[nextIndex] == NULL)
	{
		curr->next[nextIndex] = new Node();
	}

	insert(curr->next[nextIndex], databaseEntry, index + 1);
}

int query(Node *curr, string &txt, int index)
{
	// String not found.
	if (curr == NULL)
		return -1;
	// String found.
	if (index == txt.length())
	{
		return curr->maxSubtree;
	}

	// The next character that we need.
	int nextIndex = (int)(txt[index] - 'a');
	return query(curr->next[nextIndex], txt, index + 1);
}

vector<int> searchEngine(vector<pair<string, int> > database, vector< string > text)
{
	// Creating a Trie data-structure.
	Node *root = new Node();
	int n = database.size();

	for (int i = 0; i < n; i++)
	{
		insert(root, database[i], 0);
	}

	vector<int> ans;
	// Iterating in each query.
	for (auto &i: text)
	{
		// Appending the answer in 'ans'.
		ans.push_back(query(root, i, 0));
	}

	delete root;
	return ans;
}
