public class LLStringTest
{
	public static void main(String[] ar)
	{
		LLString llstr = new LLString("Programming");
		System.out.println(llstr.charAt(2));
		System.out.println(llstr.length());
		System.out.println(llstr.toString());
        System.out.println(llstr.compareTo("Program"));
        System.out.println(llstr.compareTo("Euthanasia"));
        System.out.println(llstr.compareToIgnoreCase("PROGRAM"));
        System.out.println(llstr.compareToIgnoreCase("EUTHANASIA"));
        LLString newllstr1 = new LLString("Program");
        LLString newllstr2 = new LLString("Euthanasia");
        LLString newllstr3 = new LLString("PROGRAM");
        LLString newllstr4 = new LLString("EUTHANASIA");
        System.out.println(llstr.compareTo(newllstr1));
        System.out.println(llstr.compareTo(newllstr2));
        System.out.println(llstr.compareToIgnoreCase(newllstr3));
        System.out.println(llstr.compareToIgnoreCase(newllstr4));
        System.out.println(llstr.concat("Java").toString());
        LLString java = new LLString("Java");
        System.out.println(llstr.concat(java).toString());
        System.out.println(llstr.indexOf((int) 'r'));
        System.out.println(llstr.indexOf((int) 'r', 2));
        System.out.println(llstr.indexOf("gram"));
        System.out.println(llstr.indexOf("gram", 2));
        System.out.println(llstr.length());
        System.out.println(llstr.replace('r', 'a').toString());
        System.out.println(llstr.substring(3));
        System.out.println(llstr.substring(0, 3));
	}
}

