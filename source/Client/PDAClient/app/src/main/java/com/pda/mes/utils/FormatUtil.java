package com.pda.mes.utils;

import java.text.DateFormat;
import java.text.DecimalFormat;
import java.text.SimpleDateFormat;

/**
 * Created by sjs on 2020. 09. 24
 */
public class FormatUtil {

    public static String toNumFormat(double num) {

        DecimalFormat df = new DecimalFormat("#,###.##");

        return df.format(num);
    }


    public static String toNumFormat(int num) {

        DecimalFormat df = new DecimalFormat("#,###");

        return df.format(num);
    }

    public static String toNumFormat(long num) {

        DecimalFormat df = new DecimalFormat("#,###");

        return df.format(num);
    }

    public static int convertStringToInteger(String value) {

        int reValue;

        try {
            reValue = (int)Double.parseDouble(value);
        } catch(Exception e) {
            reValue = 0;
        }

        return reValue;
    }

    public static double convertStringToDouble(String value) {

        double reValue;

        try {
            reValue = Double.parseDouble(value);
        } catch(Exception e) {
            reValue = 0;
        }

        return reValue;
    }

    public static String convertStringToDateType(String date) {
        try {
            DateFormat inputFormat = new SimpleDateFormat("yyyyMMdd");
            DateFormat outputFormat = new SimpleDateFormat("yyyy-MM-dd");
            return outputFormat.format(inputFormat.parse(date));
        }
        catch (Exception e) {
            return date;
        }
    }

    public static String convertT2Barcode(String barcode) {
        if(barcode.length() > 20)
            return " " + barcode;
        return barcode;
    }

    public static String convert20POID(String poId) {
        if(StringUtil.isNullOrEmpty(poId) || poId.trim().length() < 8)
            return poId;

        try {
            Integer.parseInt(poId.trim().substring(0, 8));
            return poId.trim();
        }
        catch (NumberFormatException e) {
            return "20" + poId.trim();
        }
    }
}
