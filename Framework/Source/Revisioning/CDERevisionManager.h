//
//  CDERevisionManager.h
//  Ensembles
//
//  Created by Drew McCormack on 25/08/13.
//  Copyright (c) 2013 Drew McCormack. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

#import "CDEDefines.h"  

@class CDEEventStore;
@class CDERevisionSet;

@interface CDERevisionManager : NSObject

@property (nonatomic, readonly) CDEEventStore *eventStore;
@property (nonatomic, readonly) NSManagedObjectContext *eventManagedObjectContext;

- (instancetype)initWithEventStore:(CDEEventStore *)eventStore eventManagedObjectContext:(NSManagedObjectContext *)context;
- (instancetype)initWithEventStore:(CDEEventStore *)eventStore;

- (NSArray *)fetchUncommittedStoreModificationEvents:(NSError * __autoreleasing *)error;
- (NSArray *)fetchStoreModificationEventsConcurrentWithEvents:(NSArray *)events error:(NSError * __autoreleasing *)error;

- (BOOL)checkIntegrationPrequisites:(NSError * __autoreleasing *)error;
- (BOOL)checkModelVersionIsCurrent;
- (BOOL)checkAllDependenciesExistForStoreModificationEvents:(NSArray *)events;
- (BOOL)checkContinuityOfStoreModificationEvents:(NSArray *)events;

- (CDEGlobalCount)maximumGlobalCount;
- (CDERevisionSet *)revisionSetOfMostRecentEvents;

- (NSArray *)sortStoreModificationEvents:(NSArray *)events;


@end
