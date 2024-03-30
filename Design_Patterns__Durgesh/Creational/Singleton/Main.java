package Singleton;

public class Main {
    public static void main(String[] args) {
        Singleton s = Singleton.getSingleton();
        System.out.println(s.hashCode());

        Singleton p = Singleton.getSingleton();
        System.out.println(p.hashCode());

        System.out.println(Jalebi.getJalebi().hashCode());
        System.out.println(Jalebi.getJalebi().hashCode());

    }
}
