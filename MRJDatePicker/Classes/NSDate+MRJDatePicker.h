//
//  NSDate+MRJDatePicker.h
//  MRJDatePickerDeomo
//
//  Created by MRJ on 6/21/18.
//  Copyright © 2016 MRJ. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const kDateFormatYYYYMMDD;
extern NSString *const kDateFormatYYMMDDTHHmmss;

@interface NSDate (MRJDatePicker)

+ (NSDateFormatter *)shareDateFormatter;

- (NSInteger)daysBetween:(NSDate *)aDate;
- (NSDate *)dateByAddingDays:(NSInteger)days;
- (NSString *)stringForFormat:(NSString *)format;


@end

@interface NSCalendar (AT)

+ (instancetype)sharedCalendar;

@end
