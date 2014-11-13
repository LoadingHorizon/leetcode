import java.lang.reflect.Method;

public class Test {
    private static Method push_;
    private static Method pop_;
    private static Method top_;
    private static Method getMin_;
    private static Class class_;

    private static void test_cases() throws Throwable {
        test_case();
        // TODO add your case here
    };

    private static void test_case() throws Throwable {
        try {
            int top;
            int min;
            Object object = class_.newInstance();
            push_.invoke(object, 2147483646);
            push_.invoke(object, 2147483646);
            push_.invoke(object, 2147483647);
            top = (int) top_.invoke(object);
            assert top == 2147483647;
            pop_.invoke(object);
            min = (int) getMin_.invoke(object);
            assert min == 2147483646;
            pop_.invoke(object);
            min = (int) getMin_.invoke(object);
            pop_.invoke(object);
            push_.invoke(object, 2147483647);
            top = (int) top_.invoke(object);
            min = (int) getMin_.invoke(object);
            push_.invoke(object, -2147483648);
            top = (int) top_.invoke(object);
            min = (int) getMin_.invoke(object);
            assert min == -2147483648;
            pop_.invoke(object);
            min = (int) getMin_.invoke(object);
        } catch (AssertionError e) {
            System.out.println("test case failed: ");
        }
    }

    @SuppressWarnings("unchecked")
    public static void test(Class c) throws Throwable {
        class_ = c;
        getMin_ = c.getMethod("getMin", new Class[]{});
        push_ = c.getMethod("push", new Class[]{int.class});
        pop_ = c.getMethod("pop", new Class[]{});
        top_ = c.getMethod("top", new Class[]{});
        test_cases();
    }

    public static void main(String[] args) throws Throwable {
        if (args.length != 1) {
            System.out.println("Usage: java -ea Test <package>");
            System.out.println("    eg: java -ea Test pj");
            System.out.println("    eg: java -ea Test hl");
            return;
        }

        test(Class.forName(args[0] + ".MinStack"));
    }
}
