void q_sort(queue_t *q)
{
    char *pivot;
    int i = 0;
    list_ele_t *beg[q->size + 1], *end[q->size + 1], *junc = NULL;
    for (int j = 0; j <= q->size; ++j) {
        beg[j] = NULL;
        end[j] = NULL;
    }
    beg[0] = q->head;
    end[0] = q->tail;
    while (i >= 0) {
        list_ele_t *lh = beg[i], *rh = beg[i], *lt = beg[i], *rt = beg[i];
        if (beg[i] != end[i]) {
            pivot = beg[i]->value;
            list_ele_t *p = beg[i];
            while (p != end[i]) {
                p = p->next;
                if (strcasecmp(p->value, pivot) < 0) {
                    lt = (lh != beg[i]) ? (lt->next = p) : (lh = p);
                } else {
                    rt = (rh != beg[i]) ? (rt->next = p) : (rh = p);
                }
            }
            lt->next = beg[i];
            beg[i]->next = rh;
            rt->next = NULL;

            beg[i + 1] = beg[i];
            end[i + 1] = beg[i];
            beg[i] = lh;
            end[i] = lt;
            beg[i + 2] = rh;
            end[i + 2] = rt;
            i += 2;
        } else {
            if (beg[i] != junc)
                beg[i]->next = junc;
            junc = beg[i];
            i--;
        }
    }
    q->tail = q->head = beg[0];
    while (q->tail->next)
        q->tail = q->tail->next;
}