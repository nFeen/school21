import re

def convert_image_links(input_file, output_file):
    # Read the input file
    with open(input_file, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Counter for image numbers
    image_counter = 1
    
    # Function to replace each match
    def replace_match(match):
        nonlocal image_counter
        timestamp = match.group(1)
        replacement = f'![image{image_counter}](<Images/Pasted image {timestamp}.png>)'
        image_counter += 1
        return replacement
    
    # Find and replace all image links
    pattern = re.compile(r'!\[\[Pasted image (\d{14})\.png\]\]')
    new_content = pattern.sub(replace_match, content)
    
    # Write the modified content to the output file
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write(new_content)
    
    print(f"Converted {image_counter-1} image links. Output written to {output_file}")

# Example usage
input_file = 'Readme.md'  # Change to your input file
output_file = 'converted_note.md'  # Change to your desired output file
convert_image_links(input_file, output_file)