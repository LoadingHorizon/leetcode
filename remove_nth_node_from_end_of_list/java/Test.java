import java.lang.reflect.Method;
import lc.ListNode;

public class Test {
    private static Method method_;
    private static Class class_;

    private static void test_cases() throws Throwable {
        ListNode head   = new ListNode(1);
        head.next       = new ListNode(2);
        head.next.next  = new ListNode(3);
        ListNode expect = new ListNode(1);
        expect.next     = new ListNode(3);
        test_case(new Object[]{head, 2}, expect);
        // TODO add your case here
    };

    private static void test_case(Object[] args, Object ret) throws Throwable {
        ListNode result = (ListNode) method_.invoke(class_.newInstance(), args);
        ListNode expect = (ListNode) ret;
        try {
            ListNode node1 = result;
            ListNode node2 = expect;
            while (node1 != null) {
                assert node2 != null;
                assert node1.val == node2.val;
                node1 = node1.next;
                node2 = node2.next;
            }
            assert node2 == null;
        } catch (AssertionError e) {
            ListNode head = (ListNode) args[0];
            int n = (int) args[1];
            System.out.println("test case failed: ");
            System.out.println("    head: " + listNodeToString(head));
            System.out.println("    n: " + args[1]);
            System.out.println("    expect: " + listNodeToString(expect));
            System.out.println("    result: " + listNodeToString(result));
        }
    }

    public static String listNodeToString(ListNode node) {
        String listStr = "";
        while (node != null) {
            listStr += node.val + "->";
            node = node.next;
        }
        return listStr.substring(0, listStr.length() - 2);
    }

    @SuppressWarnings("unchecked")
    public static void test(Class c) throws Throwable {
        class_ = c;
        method_ = c.getMethod("removeNthFromEnd", new Class[]{ListNode.class, int.class});
        test_cases();
    }

    public static void main(String[] args) throws Throwable {
        if (args.length != 1) {
            System.out.println("Usage: java -ea Test <package>");
            System.out.println("    eg: java -ea Test pj");
            System.out.println("    eg: java -ea Test hl");
            return;
        }

        test(Class.forName(args[0] + ".Solution"));
    }
}
