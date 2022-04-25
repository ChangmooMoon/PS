public class ArrayList {
    private final Object[] elementData = new Object[100];
    private int size = 0;

    public boolean add(Object element) {
        elementData[size++] = element;
        return true;
    }

    public boolean add(int idx, Object element) {
        if (idx > this.size)
            return false;

        for (int i = size - 1; i >= idx; --i) {
            elementData[i + 1] = elementData[i];
        }
        elementData[idx] = element;
        ++size;
        return true;
    }

    public void addFirst(Object element) {
        this.add(0, element);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < size; ++i) {
            sb.append(elementData[i]);
            if (i < size - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }

    public Object remove(int idx) {
        Object removed = elementData[idx];
        for (int i = idx + 1; i < size; ++i) {
            elementData[i - 1] = elementData[i];
        }
        --size;
        elementData[size] = null;
        return removed;
    }

    public Object removeFirst() {
        return remove(0);
    }

    public Object removeLast() {
        return remove(size - 1);
    }

    public Object get(int idx) {
        return elementData[idx];
    }

    public int size() {
        return size;
    }

    public Object indexOf(Object o) {
        for (int i = 0; i < this.size; ++i) {
            if (o.equals(elementData[i]))
                return i;
        }
        return -1;
    }

    public ListIterator listIterator() {
        return new ListIterator();
    }

    class ListIterator {
        private int nextIdx = 0;

        public boolean hasNext() {
            return nextIdx < size();
        }

        public Object next() {
            return elementData[nextIdx++];
        }

        public boolean hasPrevious() {
            return nextIdx > 0;
        }

        public Object previous() {
            return elementData[--nextIdx];
        }

        public void add(Object element) {
            ArrayList.this.add(nextIdx++, element);
        }

        public void remove() {
            ArrayList.this.remove(nextIdx - 1);
            --nextIdx;
        }
    }
}