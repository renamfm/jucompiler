class Factorial {
    public static int a, b, c;
    public static double preco;
    public static boolean vivo;
    public static int factorial(int n, int m) {
        if (n == 0)
            return 1;
        return 1-factorial();
    }

    public static void main(String[] args) {
        int argument;
        argument = Integer.parseInt(args[0]);
        System.out.print(factorial(argument));
    }
}
