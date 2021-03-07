void q_sort(queue_t *q)
{
    char *pivot;
    int i = 0;
    list_ele_t *beg[q->size], *end[q->size];
    list_ele_t *l, *r, *pr;
    beg[0] = q->head;
    end[0] = q->tail;
    while (i >= 0) {
        l = beg[i];
        r = end[i];
        if (l && r && l != r) {
            pivot = l->value;
            while (l != r) {
                pr = r = l;
                while (pr != end[i]) {  // find the last one smaller than pivot
                    pr = pr->next;
                    if (strcasecmp(pr->value, pivot) < 0)
                        r = pr;
                }

                if (r != l) {  // found
                    l->value = r->value;
                    l = l->next;
                }

                while (strcasecmp(l->value, pivot) <= 0 &&
                       l != r) {  // find the first one bigger than pivot
                    l = l->next;
                }

                if (l != r) {
                    r->value = l->value;
                }
            }
            l->value = pivot;
            beg[i + 1] = l->next;
            end[i + 1] = end[i];
            end[i++] = l;
        } else {
            i--;
        }
    }
}