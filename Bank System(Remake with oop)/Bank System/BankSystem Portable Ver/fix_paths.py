import os

# Define replacements mapping
# Order matters! Specific paths first.
replacements = [
    (r'E:\projects\c++ course\10-OOP Concepts\Project 2\Project 2\clsString.h', r'Lib/clsString.h'),
    (r'E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Utility Library', r'Lib'),
    (r'E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library', r'Lib'),
    (r'E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System', r''),
    (r'E:\projects\my library', r''),
]

# Function to replace in content
def process_content(content):
    new_content = content
    for old, new in replacements:
        # Replace normal backslashes
        new_content = new_content.replace(old, new)
        # Replace escaped backslashes just in case (though usually in #include they are single unless weirdly escaped)
        # Windows paths in C++ includes are usually single backslash inside quotes.
        
    # Also Normalize slashes in #include lines to forward slashes for consistency?
    # Maybe step by step.
    
    # Fix potential double slashes or leading slash issues
    # If replacement was empty string, we might have include "\Core Features"
    new_content = new_content.replace('#include "\\', '#include "')
    new_content = new_content.replace('#include "Lib\\', '#include "Lib/')
    new_content = new_content.replace('#include "Core Features\\', '#include "Core Features/')
    new_content = new_content.replace('#include "Screens\\', '#include "Screens/')
    new_content = new_content.replace('#include "Ui\\', '#include "Ui/')
    new_content = new_content.replace('#include "CurrencyExchange\\', '#include "CurrencyExchange/')
    
    # Normalize backslashes to forward slashes in includes
    lines = new_content.splitlines()
    final_lines = []
    for line in lines:
        if line.strip().startswith('#include'):
            # Replace backslashes with forward slashes only in this line
            line = line.replace('\\', '/')
            # Cleanup double slashes //
            line = line.replace('//', '/') # Careful with comments? #include usually doesn't have comments inline like this
            # Actually, standard include doesn't use // for path sep.
            # But keep // for comments.
            # Simple replace \ -> /
        final_lines.append(line)
        
    return '\n'.join(final_lines)

# Walk directory
root_dir = "."
for dirpath, dirnames, filenames in os.walk(root_dir):
    for filename in filenames:
        if filename.endswith(".h") or filename.endswith(".cpp"):
            filepath = os.path.join(dirpath, filename)
            
            with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read()
            
            new_content = process_content(content)
            
            if new_content != content:
                print(f"Updating {filepath}")
                with open(filepath, 'w', encoding='utf-8') as f:
                    f.write(new_content)
