class Firm {
    private List<Integer> income;

    public Firm(int n) {
        income = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            income.add(0);
        }
    }

    public void assignSalaries(List<Integer> salaries) {
        int n = salaries.size();
        for (int i = 0; i < n && i < income.size(); i++) {
            income.set(i, salaries.get(i));
        }
    }

    public float averageSalary() {
        int total = 0;
        for (int i = 0; i < income.size(); i++) {
            total += income.get(i);
        }
        int x = income.size();
        float avg = (float) total / x;
        return avg;
    }

    public int maxSalary() {
        int maxy = Integer.MIN_VALUE;
        for (int i = 0; i < income.size(); i++) {
            maxy = Math.max(maxy, income.get(i));
        }
        return maxy;
    }

    public int minSalary() {
        int miny = Integer.MAX_VALUE;
        for (int i = 0; i < income.size(); i++) {
            miny = Math.min(miny, income.get(i));
        }
        return mminy;
    }

    // Getter for income to be used by derived classes
    protected List<Integer> getIncome() {
        return income;
    }
}

// EngineerFirm class inheriting from Firm
class EngineerFirm extends Firm {

    public EngineerFirm(int n) {
        super(n);
    }

    @Override
    public void assignSalaries(List<Integer> salaries) {
        super.assignSalaries(salaries);
        System.out.println("Incomes of engineers credited");
    }

    @Override
    public void averageSalary() {
        float avg = super.averageSalary();
        System.out.println("Average salary of engineers is " + avg);
    }

    @Override
    public void maxSalary() {
        int sal super.maxSalary();
        System.out.println("Maximum salary amongst engineers is " + sal);
    }

    @Override
    public void minSalary() {
        int sal = super.minSalary();
        System.out.println("Minimum salary amongst engineers is " + sal);
    }
}

// AccountantFirm class inheriting from Firm
class AccountantFirm extends Firm {

    public AccountantFirm(int n) {
        super(n);
    }

    @Override
    public void assignSalaries(List<Integer> salaries) {
        super.assignSalaries(salaries);
        System.out.println("Incomes of accountants credited");
    }

    @Override
    public void averageSalary() {
        float avg = super.averageSalary();
        System.out.println("Average salary of accountants is " + avg);
    }

    @Override
    public void maxSalary() {
        int sal = super.maxSalary();
        System.out.println("Maximum salary amongst accountants is " + sal);
    }

    @Override
    public void minSalary() {
        int sal = super.minSalary();
        System.out.println("Minimum salary amongst accountants is " + sal);
    }
}