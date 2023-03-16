package Playground;

import java.util.Random;
import java.util.Scanner;

//first we define a class called pet, this contains everything a pet has, including stats.
class pet {
    int hp;
    int atk;
    int def;
    String petname;
}

public class petgame {
    static Scanner scan = new Scanner(System.in);
    static Random rand = new Random();

    //a stolen method for delays
        public static void wait(int ms)
    {
        try
        {
            Thread.sleep(ms);
        }
        catch(InterruptedException ex)
        {
            Thread.currentThread().interrupt();
        }
    }

    //generates a stat
    public static int genstat(int level) {
        return rand.nextInt(level * 10 + 1);
    }
    
    //generates a new pet with stats relevant to its level
    public static void genpet(pet pett, String name) { 
        pett.petname = name;
        pett.hp = genstat(10);
        pett.atk = genstat(1);
        pett.def = genstat(1);
    }

    //lists out everything to know about the pet
    public static void info(pet pett) {
    System.out.println("Name:" + pett.petname + "\nStats:\n\tHP:" + pett.hp + "\n\tAttack:" + pett.atk + "\n\tDefense:" + pett.def); 
    }

    //attack works simply for now, just substract enemy def from pet atk and put some rng, then substract the dmg !!IMPROVE!!
    public static void attack(pet pet1, pet pet2) {
        System.out.println(pet1.petname + " attacks!");
        wait(1000);
        int dmg = pet1.atk - pet2.def + rand.nextInt(6) - rand.nextInt(4);
        if (dmg <= 0) { dmg = 1; } //so that you don't end up healing the opponent
        pet2.hp -= dmg;
        System.out.println(pet2.petname + " took " + dmg + " damage!");
        wait(1000);
    }

    //battle works simply also, just attack in turns, pet1 always starts first and they take equal turns because there is no spd stat yet !!IMPROVE!!
    public static void battle(pet pet1, pet pet2) {
        while (pet1.hp > 0 && pet2.hp > 0) {
            attack(pet1,pet2);
            if (pet2.hp <= 0) {
                System.out.println(pet2.petname + " can't fight anymore!\n" + pet1.petname + " wins!");
                wait(1000);
                break;
            }
            attack(pet2,pet1);
            if (pet1.hp <= 0) {
                System.out.println(pet1.petname + " can't fight anymore!\n" + pet2.petname + " wins!");
                wait(1000);
                break;
            }
        }
    }

public static void main(String[] args) {
        pet pcpet = new pet(); //make our pet

        genpet(pcpet, "null");
        System.out.println("What is your pet's name?");
        while (true) {
            pcpet.petname = scan.nextLine();
            if (pcpet.petname.isEmpty() == true || pcpet.petname.length() > 15)  {
                System.out.println("Name either empty or too long. Try again.");
            }
            else {
                break;
            }
        }
        info(pcpet);

        pet enemy = new pet(); //make the enemy
        genpet(enemy, "enemypet");
        info(enemy);     

        battle(pcpet, enemy);
    }
}

