int linker[MAXN * 2];
bool used[MAXN * 2];

bool dfs(int u) {
    for (int i = he[u]; i; i = ne[i]) {
        int v = ed[i];
        if (!used[v]) {
            used[v] = true;
            if (linker[v] == -1 || dfs(linker[v])) {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungarian(int n) {
    int res = 0;
    for (int i = 0; i <= n * 2; i++) linker[i] = -1;
    for (int u = 1; u <= 1; u++) {
        for (int i = 1; i <= n * 2; i++) used[i] = 0;
        if (dfs(u)) res++;
    }
    return res;
}