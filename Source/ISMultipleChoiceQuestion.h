/*
 By: Justin Meiners
 
 Copyright (c) 2013 Inline Studios
 Licensed under the MIT license: http://www.opensource.org/licenses/mit-license.php
 */

#import <Foundation/Foundation.h>
#import "ISQuestion.h"

@interface ISMultipleChoiceResponse : ISQuestionResponse
@property(nonatomic, assign)int answerIndex;
@property(nonatomic, strong)NSArray* answerIndexes;

+ (ISMultipleChoiceResponse*)responseWithAnswerIndex:(int)answerIndex;

- (id)init;
- (id)initWithAnswerIndex:(int)answerIndex;
- (id)initWithAnswerIndexes:(NSArray*)answerIndexes;

- (id)initWithCoder:(NSCoder *)aDecoder;
- (void)encodeWithCoder:(NSCoder *)aCoder;

- (id)initWithIndex:(int)answerIndex;
- (id)initWithIndexes:(NSArray*)answerIndexes;

+ (ISMultipleChoiceResponse*)responseWithIndex:(int)index;
+ (ISMultipleChoiceResponse*)responseWithIndexes:(NSArray*)indexes;

@end

@interface ISMultipleChoiceOption : NSObject <NSCoding>
@property(nonatomic, strong) NSDictionary* userData;
@property(nonatomic, copy) NSString* text;
@property(nonatomic, assign) BOOL correct;
@property(nonatomic, assign) BOOL preSelected;

- (id)initWithCoder:(NSCoder *)aDecoder;
- (void)encodeWithCoder:(NSCoder *)aCoder;

- (id)initWithText:(NSString*)text correct:(BOOL)correct;

- (id)initWithText:(NSString*)text
           correct:(BOOL)correct
          userData:(NSDictionary*)userData;

+ (ISMultipleChoiceOption*)optionWithText:(NSString*)text correct:(BOOL)correct;

@end

@interface ISMultipleChoiceQuestion : ISQuestion

@property(nonatomic, strong)NSArray* options;
@property(nonatomic, strong)NSArray* correctOptions;
@property(nonatomic, strong, readonly) NSArray* randomizedOptions;
@property(nonatomic, strong)NSNumber* selectableOptions;

- (id)initWithCoder:(NSCoder *)aDecoder;
- (void)encodeWithCoder:(NSCoder *)aCoder;

- (void)addOption:(ISMultipleChoiceOption*)option;
- (void)addOptions:(NSArray*)options;
- (void)removeAllOptions;

- (BOOL)responseCorrect:(ISQuestionResponse*)response;

- (BOOL)responseCorrectForRandomizedOptions:(ISQuestionResponse*)response;

-(NSArray*)calculateCorrectFromOptions:(NSArray*)options;

@end


