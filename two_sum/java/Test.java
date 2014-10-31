import java.lang.reflect.Method;

public class Test {
    private static Method method_;
    private static Class class_;

    private static void test_cases() throws Throwable {
        test_case(new Object[]{new int[]{1, 3, 4, 2}, 5}, new int[]{1, 3});
        test_case(new Object[]{new int[]{1, 3, 2, 4}, 5}, new int[]{2, 3});
        test_case(new Object[]{new int[]{1, 2, 3, 4}, 7}, new int[]{3, 4});
    };

    private static void test_case(Object[] args, Object ret) throws Throwable {
        int[] result = (int[]) method_.invoke(class_.newInstance(), args);
        int[] expect = (int[]) ret;
        try {
            assert result[0] == expect[0];
            assert result[1] == expect[1];
        } catch (AssertionError e) {
            int[] numbers = (int[]) args[0];
            int target = (int) args[1];
            String str_numbers = "{";
            for (int num : numbers) {
                str_numbers += (num + ", ");
            }
            str_numbers += "}";
            System.out.println("test case: ");
            System.out.println("    numbers: " + str_numbers);
            System.out.println("    target: " + target);
            System.out.println("    expect: {" + expect[0] + ", " + expect[1] + "}");
            System.out.println("    result: {" + result[0] + ", " + result[1] + "}");
        }
    }

    @SuppressWarnings("unchecked")
    public static void test(Class c) throws Throwable {
        class_ = c;
        method_ = c.getMethod("twoSum", new Class[]{int[].class, int.class});
        test_cases();
    }

    public static void main(String[] args) throws Throwable {
        if (args.length != 1) {
            System.out.println("Usage: java -ea Test <package>");
            System.out.println("    eg: java -ea Test pj");
            System.out.println("    eg: java -ea Test hl");
            return;
        }

        try {
            Class solution = Class.forName(args[0] + ".Solution");
            test(solution);
        } catch (AssertionError exception) {
            System.out.println("test case failed.");
        }
    }
}
