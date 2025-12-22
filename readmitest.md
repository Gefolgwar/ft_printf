graph TD
    classDef sub opacity:0
    classDef note fill:#ffd, stroke:#ccb
    
    A --> B
    A & B --> C
    
    subgraph subA [" "]
        A
        noteA[I AM THE FIRST NOTE]
    end
    
    subgraph subB [" "]
        B
        noteB[I AM THE SECOND NOTE]
    end
    
    subgraph subC [" "]
        C
        noteC[I AM THE THIRD NOTE<br>...WITH 2 LINES]
    end
    
    class subA,subB,subC sub
    class noteA,noteB,noteC note