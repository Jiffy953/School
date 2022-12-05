import java.util.*;

//this is so broken I have no idea what does anything anymore


public class election {
    abstract static class Person
    {
        public int age;
        public char gender;
        protected String firstName;
        protected String lastName;
        protected String politicalParty;
        Person()
        {

        }
        Person(int age, char gender, String firstName, String lastName, String politicalParty)
        {
            this.age=age;
            this.gender=gender;
            this.firstName=firstName;
            this.lastName=lastName;
            this.politicalParty=politicalParty;
        }

        public int getAge() {
            {
                return age;
            }
        }

        public char getGender()
        {
            return gender;
        }
        public String getFullName()
        {
            return firstName + " " + lastName;
        }
    }

     public class Candidate extends Person
    {
        private int voteCount = 0;
        Candidate()
        {
        }
        Candidate(int age, char gender, String firstName, String lastName, String politicalParty)
        {
            super.age=age; //maybe make public idk how here
            super.gender=gender; //here too
            super.firstName=firstName;
            super.lastName=lastName;
            super.politicalParty=politicalParty;
            /*super(age);
            super(gender);
            super(firstName);
            super(lastName);
            super(politialParty);*/
        }

        public int getVoteCount() {
            return voteCount;
        }
        public void incrementVoteCount()
        {
            voteCount++;
        }
        @Override
        public String getFullName() {
            return super.getFullName() + " - " + politicalParty;
        }

    }

    public class Voter extends Person
    {
        private int voterid;
        private boolean voted = false;
        Voter()
        {
        }
        Voter(int voterId, int age, char gender, String firstName, String lastName, String politicalParty)
        {
            this.age=age; //maybe make public idk how here
            this.gender=gender; //here too
            this.firstName=firstName;
            this.lastName=lastName;
            this.politicalParty=politicalParty;
        }

        public int getVoterid() {
            return voterid;
        }
        public boolean hasVoted()
        {
            return voted;
        }

        @Override
        public String getFullName() {
            return super.getFullName();
        }
    }

    static class VotingMachine
    {
        public Candidate[] candidates;

        VotingMachine(Candidate candidates[])
        {
            this.candidates = candidates;
        }

        public void vote(Voter v, Candidate c)
        {
            candidates++;
        }
        public void vote(Voter v)
        {

        }
        public void tally()
        {

        }
        
    }

    public static void main(String[] args)
    {
        Candidate janeDoe = new Candidate(35, 'F', "Jane", "Doe", "Republican");
        Candidate johnSmith = new Candidate(35, 'M', "John", "Smith", "Democrat");
        Candidate fredJohnson = new Candidate(35, 'M', "Fred", "Johnson", "Non-Affiliate");

        Candidate candidates[] = {janeDoe, johnSmith, fredJohnson};

        VotingMachine vm = new VotingMachine(candidates);

        Voter v1 = new Voter(1, 20, 'M', "Martin", "Amis", "Non-Affiliate");
        vm.vote(v1, janeDoe);

        Voter v2 = new Voter(2, 45, 'F', "Jane", "Smith", "Republican");
        vm.vote(v2, janeDoe);

        Voter v3 = new Voter(3, 31, 'M', "John", "Johnson", "Democrat");
        vm.vote(v3, johnSmith);

        Voter v4 = new Voter(4, 35, 'M', "Tommy", "Bradon", "Non-Affiliate");
        vm.vote(v4, janeDoe);

        Voter v5 = new Voter(5, 27, 'M', "Bob", "Dylan", "Non-Affiliate");
        vm.vote(v5, johnSmith);

        Voter v6 = new Voter(6, 27, 'F', "Ellie", "Smith", "Democrat");
        vm.vote(v6, janeDoe);

        Voter v7 = new Voter(7, 30, 'F', "Lilly", "Frederick", "Non-Affiliate");
        vm.vote(v7, fredJohnson);

        vm.tally();
    }

}
