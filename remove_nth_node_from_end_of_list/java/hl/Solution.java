// @file Solution.java
// @desc 先求长度
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-11-09

package hl;
import lc.ListNode;

public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null) {
            return null;
        }
        ListNode node = head;
        int len = 0;
        while (node != null) {
            len++;
            node = node.next;
        }
        n = len - n;

        if (n < 0) {
            return head;
        } else if (n == 0) {
            return head.next;
        } else if (n >= len) {
            return head;
        }

        ListNode node1 = head;
        ListNode node2 = head.next;
        for (int i = 0; i < n - 1; i++) {
            node1 = node1.next;
            node2 = node2.next;
        }

        node1.next = node2.next;
        return head;
    }
}
